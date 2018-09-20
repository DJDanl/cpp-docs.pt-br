---
title: Detalhes do suporte ATL adicionado pelo assistente ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.codewiz.atl.support
dev_langs:
- C++
helpviewer_keywords:
- MFC, ATL support
- ATL, MFC projects
ms.assetid: aa66bad0-008f-4886-94c1-2a0a0d04bce4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: efa96037139e61e16b752b45617bb8a3c54be993
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46442143"
---
# <a name="details-of-atl-support-added-by-the-atl-wizard"></a>Detalhes do suporte ATL adicionado pelo Assistente ATL

Quando você [adicionar suporte ATL a um executável do MFC ou DLL existente](../../mfc/reference/adding-atl-support-to-your-mfc-project.md), o Visual C++ torna as seguintes modificações ao projeto MFC existente (neste exemplo, o projeto é chamado `MFCEXE`):

- Dois novos arquivos (um arquivo. idl e um arquivo. rgs, usado para registrar o servidor) são adicionados.

- Nos principais arquivos do aplicativo cabeçalho e de implementação (Mfcexe.h e Mfcexe.cpp), uma nova classe (derivado de `CAtlMFCModule`) é adicionado. Além da nova classe, o código é adicionado ao `InitInstance` para o registro. Código também é adicionado para o `ExitInstance` função para revogar o objeto de classe. No arquivo de cabeçalho, por fim, dois novos arquivos de cabeçalho (initguid e Mfcexe_i.c) estão incluídos no arquivo de implementação, a declaração e inicialização de novos GUIDs para o `CAtlMFCModule`-classe derivada.

- Para registrar o servidor corretamente, uma entrada para o novo arquivo. rgs é adicionada ao arquivo de recurso do projeto.

## <a name="notes-for-dll-projects"></a>Notas para os projetos DLL

Quando você adiciona suporte ATL em um projeto de DLL do MFC, você verá algumas diferenças. Código é adicionado para o `DLLRegisterServer` e `DLLUnregisterServer` funções para registrar e cancelar o registro da DLL. Código também é adicionado ao [DllCanUnloadNow](../../atl/reference/catldllmodulet-class.md#dllcanunloadnow) e [DllGetClassObject](../../atl/reference/catldllmodulet-class.md#dllgetclassobject).

## <a name="see-also"></a>Consulte também

[Suporte ATL em um projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)<br/>
[Adicionando uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)<br/>
[Adicionando uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)<br/>
[Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)<br/>
[Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)<br/>
[Navegando pela estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
