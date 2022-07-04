void AddModel(IDirect3DDevice9* Device, UINT Color, char* Name)
{
    D3DVIEWPORT9 Viewport;
    D3DXMATRIX ViewProjectionMatrix, WorldToLocal;
    D3DXVECTOR3 Vector3D(0, 0, 0), Vector2D;
 
    Device->GetViewport(&Viewport);
    Device->GetVertexShaderConstantF(0, ViewProjectionMatrix, 4);
 
    D3DXMatrixIdentity(&WorldToLocal);
    D3DXMatrixTranspose(&WorldToLocal, &ViewProjectionMatrix);
    D3DXVec3TransformCoord(&Vector2D, &Vector3D, &WorldToLocal);
 
    if (Vector2D.z < 1.0f && ViewProjectionMatrix._44 > 1.0f)
    {
        D3DXVECTOR3 Location;
        Location.x = Viewport.X + (1.0f + Vector2D.x) * Viewport.Width / 2.0f;
        Location.y = Viewport.Y + (1.0f - Vector2D.y) * Viewport.Height / 2.0f;
        ModelInfo_t pModelInfo = { Location.x, Location.y, Color, Name };
        ModelInfo.push_back(pModelInfo);
    }
}