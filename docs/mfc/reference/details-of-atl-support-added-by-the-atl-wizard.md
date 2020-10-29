---
title: Detalhes do suporte ATL adicionado pelo Assistente ATL
ms.date: 08/20/2019
f1_keywords:
- vc.codewiz.atl.support
helpviewer_keywords:
- MFC, ATL support
- ATL, MFC projects
ms.assetid: aa66bad0-008f-4886-94c1-2a0a0d04bce4
ms.openlocfilehash: aeac01ce58deb429f14058c06524dff53abde060
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924435"
---
# <a name="details-of-atl-support-added-by-the-atl-wizard"></a>Detalhes do suporte ATL adicionado pelo Assistente ATL

::: moniker range=">=msvc-160"

Quando você [adiciona o suporte ATL a um executável ou DLL do MFC existente](../../mfc/reference/adding-atl-support-to-your-mfc-project.md), o Visual Studio adiciona um arquivo de cabeçalho chamado *Framework. h* por padrão, que contém `#include` e `#define` diretivas de pré-processador para habilitar o uso de ATL em seu projeto. Nenhum arquivo ou classe adicional é adicionado, como foi feito em versões anteriores do Visual Studio.

::: moniker-end

::: moniker range="<=msvc-150"

Quando você [adiciona o suporte ATL a um executável ou DLL do MFC existente](../../mfc/reference/adding-atl-support-to-your-mfc-project.md), o Visual Studio faz as seguintes modificações no projeto existente do MFC (neste exemplo, o projeto é chamado `MFCEXE` ):

- Dois novos arquivos (um arquivo. idl e um arquivo. rgs, usados para registrar o servidor) são adicionados.

- No cabeçalho do aplicativo principal e nos arquivos de implementação (Mfcexe. h e Mfcexe. cpp), uma nova classe (derivada de `CAtlMFCModule` ) é adicionada. Além da nova classe, o código é adicionado ao `InitInstance` para registro. O código também é adicionado à `ExitInstance` função para revogar o objeto de classe. No arquivo de cabeçalho, finalmente, dois novos arquivos de cabeçalho (Initguid. h e Mfcexe_i. c) são incluídos no arquivo de implementação, declarando e inicializando os novos GUIDs para a `CAtlMFCModule` classe derivada.

- Para registrar o servidor corretamente, uma entrada para o novo arquivo. rgs é adicionada ao arquivo de recurso do projeto.

::: moniker-end

## <a name="notes-for-dll-projects"></a>Observações para projetos de DLL

Quando você adicionar o suporte ATL a um projeto MFC DLL, verá algumas diferenças. O código é adicionado às `DLLRegisterServer` `DLLUnregisterServer` funções e para registrar e cancelar o registro da dll. O código também é adicionado a [DllCanUnloadNow](../../atl/reference/catldllmodulet-class.md#dllcanunloadnow) e [DllGetClassObject](../../atl/reference/catldllmodulet-class.md#dllgetclassobject).

## <a name="see-also"></a>Veja também

[Suporte ATL em um projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigate-code-cpp.md)
