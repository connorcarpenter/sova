//-----------------------------------------------------------------------------
// #version:49# machine generated, do not edit!
//-----------------------------------------------------------------------------
#include "Pre.h"
#include "shaders.h"

static const char* canvasVS_glsl330_src =
        "#version 330\n"
                "#ifdef GL_ARB_shading_language_420pack\n"
                "#extension GL_ARB_shading_language_420pack : require\n"
                "#endif\n"
                "\n"
                "layout(location = 0) in vec2 position;\n"
                "out vec2 uv;\n"
                "layout(location = 2) in vec2 texcoord0;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    gl_Position = vec4((position * 2.0) - vec2(1.0), 0.0, 1.0);\n"
                "    gl_Position.y = -gl_Position.y;\n"
                "    uv = texcoord0;\n"
                "}\n"
                "\n"
;
static const char* crtVS_glsl330_src =
        "#version 330\n"
                "#ifdef GL_ARB_shading_language_420pack\n"
                "#extension GL_ARB_shading_language_420pack : require\n"
                "#endif\n"
                "\n"
                "layout(location = 0) in vec4 position;\n"
                "out vec2 uv;\n"
                "layout(location = 2) in vec2 texcoord0;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    gl_Position = position;\n"
                "    uv = texcoord0;\n"
                "}\n"
                "\n"
;
static const char* nocrtFS_glsl330_src =
        "#version 330\n"
                "#ifdef GL_ARB_shading_language_420pack\n"
                "#extension GL_ARB_shading_language_420pack : require\n"
                "#endif\n"
                "\n"
                "uniform sampler2D canvas;\n"
                "\n"
                "out vec4 fragColor;\n"
                "in vec2 uv;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    fragColor = vec4(texture(canvas, uv).xyz, 1.0);\n"
                "}\n"
                "\n"
;
static const char* canvasFS_glsl330_src =
        "#version 330\n"
                "#ifdef GL_ARB_shading_language_420pack\n"
                "#extension GL_ARB_shading_language_420pack : require\n"
                "#endif\n"
                "\n"
                "uniform sampler2D tex;\n"
                "\n"
                "out vec4 fragColor;\n"
                "in vec2 uv;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    fragColor = texture(tex, uv);\n"
                "}\n"
                "\n"
;
static const char* shapeVS_glsl330_src =
        "#version 330\n"
                "#ifdef GL_ARB_shading_language_420pack\n"
                "#extension GL_ARB_shading_language_420pack : require\n"
                "#endif\n"
                "\n"
                "layout(location = 0) in vec4 position;\n"
                "out vec4 color;\n"
                "layout(location = 10) in vec4 color0;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    gl_Position = position;\n"
                "    color = color0;\n"
                "}\n"
                "\n"
;
static const char* shapeFS_glsl330_src =
        "#version 330\n"
                "#ifdef GL_ARB_shading_language_420pack\n"
                "#extension GL_ARB_shading_language_420pack : require\n"
                "#endif\n"
                "\n"
                "out vec4 fragColor;\n"
                "in vec4 color;\n"
                "\n"
                "void main()\n"
                "{\n"
                "    fragColor = color;\n"
                "}\n"
                "\n"
;
Oryol::ShaderSetup NormalShader::Setup() {
    Oryol::ShaderSetup setup("NormalShader");
    Oryol::VertexLayout crtVS_input;
    crtVS_input.Add(Oryol::VertexAttr::Position, Oryol::VertexFormat::Float4);
    crtVS_input.Add(Oryol::VertexAttr::TexCoord0, Oryol::VertexFormat::Float2);
    setup.SetInputLayout(crtVS_input);
    setup.SetProgramFromSources(Oryol::ShaderLang::GLSL330, crtVS_glsl330_src, nocrtFS_glsl330_src);
    setup.AddTexture("canvas", Oryol::TextureType::Texture2D, Oryol::ShaderStage::FS, 0);
    return setup;
}
Oryol::ShaderSetup CanvasShader::Setup() {
    Oryol::ShaderSetup setup("CanvasShader");
    Oryol::VertexLayout canvasVS_input;
    canvasVS_input.Add(Oryol::VertexAttr::Position, Oryol::VertexFormat::Float2);
    canvasVS_input.Add(Oryol::VertexAttr::TexCoord0, Oryol::VertexFormat::Float2);
    setup.SetInputLayout(canvasVS_input);
    setup.SetProgramFromSources(Oryol::ShaderLang::GLSL330, canvasVS_glsl330_src, canvasFS_glsl330_src);
    setup.AddTexture("tex", Oryol::TextureType::Texture2D, Oryol::ShaderStage::FS, 0);
    return setup;
}
Oryol::ShaderSetup ShapeShader::Setup() {
    Oryol::ShaderSetup setup("ShapeShader");
    Oryol::VertexLayout shapeVS_input;
    shapeVS_input.Add(Oryol::VertexAttr::Position, Oryol::VertexFormat::Float4);
    shapeVS_input.Add(Oryol::VertexAttr::Color0, Oryol::VertexFormat::Float4);
    setup.SetInputLayout(shapeVS_input);
    setup.SetProgramFromSources(Oryol::ShaderLang::GLSL330, shapeVS_glsl330_src, shapeFS_glsl330_src);
    return setup;
}

