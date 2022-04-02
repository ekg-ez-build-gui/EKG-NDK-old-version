/**
 * @author Rina
 * @since 21/03/2022 at 21:05PM
 */
#pragma once
#include "EKG_includes.h"
#include "EKG_abstract_ui_element.h"
#include "EKG_shader.h"
#include "EKG_tessellator.h"

/**
 * The core of EKG, where everything is processed.
 */
class EKG_Core {
protected:
    /* Buffers element used in context gui. */
    std::vector<EKG_AbstractElement*> BufferUpdate, BufferRender;

    /* Stacks. */
    EKG_Stack StackedIdsSelected;

    /* Most high id to generate unique ids. */
    unsigned int HighId;

    /* Stack control methods. */
    void ResetStack();
    void ReorderStack();

    /* Focused element (object reference instead an uint id). */
    EKG_AbstractElement* ElementFocused;
public:
    EKG_Core() {}

    /* Start of managers and controllers to EKG. */
    EKG_ShaderManager ShaderManager;
    EKG_FontRenderer FontRenderer;
    EKG_ColorTheme ColorTheme;
    /* End of managers and controllers. */

    /* Start of important methods. */
    void Init();
    void Quit();

    void AddElement(EKG_AbstractElement* Element);
    void RemoveElement(EKG_AbstractElement* Element);

    EKG_AbstractElement* GetElementById(unsigned int Id);
    unsigned int NewId();

    void Sync(float X, float Y, float W, float H, const EKG_Stack &Stack);
    /* End of important methods. */

    /* Start of concurrent methods. */
    void OnEvent(SDL_Event Event);
    void OnUpdate(float DeltaTicks);
    void OnRender(float PartialTicks);
    /* End of concurrent methods. */
};