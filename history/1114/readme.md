## Unity Commands Used

### Project Creation
- New project
- 3D Core Template
- Create project

### Hierarchy Operations
- Create → 3D Object → Cube / Sphere
- Duplicate (Ctrl + D)
- Rename
- Drag & Drop Materials / Physic Materials

### Scene Controls
- Alt + Drag (Orbit view)
- Ctrl + Alt + Drag (Pan)
- Mouse Wheel (Zoom)
- F key (Frame selected)
- Perspective ↔ Isometric toggle

### Inspector → Transform
- Position (X,Y,Z)
- Rotation (X,Y,Z)
- Scale (X,Y,Z)

### Component Menu
- Component → Physics → Rigidbody
- Rigidbody options: Use Gravity, Mass, Drag, Angular Drag

### Materials
- Create → Material
- Change Albedo color
- Apply Material by drag & drop

### Physic Materials
- Create → Physic Material
- Set Bounciness
- Apply via Collider → Material

----------------------------------

## Unity Commands Used — Character Move

### Project
- All templates
- 3D (Core)
- Create project

### Import
- Assets → Import Package → Custom Package
- Import Unity Package → All → Import

### Scripts
- Create → C# Script
- GetComponent<CharacterController>()
- controller.Move()
- GetComponent<Animator>()
- anim.SetFloat(), anim.SetTrigger()
- Input.GetAxis("Horizontal/Vertical")
- Input.GetButton("Jump")
- transform.LookAt()
- transform.forward
- Physics.gravity
- Time.deltaTime

### Terrain
- 3D Object → Terrain
- Terrain Settings (Width/Length)
- Paint Terrain (Paint Texture / Raise or Lower / Smooth Height / Stamp)
- Terrain Layers → Create Layer (Grass, Sand)
- Brush Size / Opacity
- [ ] keys to resize brush

### Character Placement
- Drag PQchan prefab into Hierarchy
- Adjust Position / Rotation
- Assign QueryChanController script

### Camera
- Adjust Main Camera Transform

### Play Mode
- Play / Pause / Step
- Controls: Arrow Keys / Space bar
