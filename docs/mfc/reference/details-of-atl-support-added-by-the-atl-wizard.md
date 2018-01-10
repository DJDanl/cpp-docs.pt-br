---
title: Detalhes do suporte ATL adicionado pelo assistente ATL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.atl.support
dev_langs: C++
helpviewer_keywords:
- MFC, ATL support
- ATL, MFC projects
ms.assetid: aa66bad0-008f-4886-94c1-2a0a0d04bce4
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 17d5063db9eb76e0fc6db9eecfe183b63276b874
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="details-of-atl-support-added-by-the-atl-wizard"></a>Detalhes do suporte ATL adicionado pelo Assistente ATL
Quando você [adicionar suporte ATL a um executável MFC existente ou uma DLL](../../mfc/reference/adding-atl-support-to-your-mfc-project.md), Visual C++ realiza as seguintes modificações para o projeto MFC existente (neste exemplo, o projeto é chamado `MFCEXE`):  
  
-   Dois novos arquivos (um arquivo. idl e um arquivo. rgs, usado para registrar o servidor) são adicionados.  
  
-   No aplicativo principal cabeçalho e implementação nos arquivos (Mfcexe.h e Mfcexe.cpp), uma nova classe (derivado de **CAtlMFCModule**) é adicionado. A nova classe, além de código é adicionado à `InitInstance` para registro. Código também é adicionado para o `ExitInstance` função para revogar o objeto da classe. No arquivo de cabeçalho, por fim, dois novos arquivos de cabeçalho (initguid. h e Mfcexe_i.c) são incluídos no arquivo de implementação, declarar e inicializar os GUIDs de novo para o **CAtlMFCModule**-classe derivada.  
  
-   Para registrar o servidor corretamente, uma entrada para o novo arquivo. rgs é adicionada ao arquivo de recurso do projeto.  
  
## <a name="notes-for-dll-projects"></a>Observações para projetos DLL  
 Quando você adicionar suporte ATL para um projeto de DLL MFC, você verá algumas diferenças. Código é adicionado para o **DLLRegisterServer** e **DLLUnregisterServer** funções para registrar e cancelar o registro da DLL. Código também é adicionado à [DllCanUnloadNow](../../atl/reference/catldllmodulet-class.md#dllcanunloadnow) e [DllGetClassObject](../../atl/reference/catldllmodulet-class.md#dllgetclassobject).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte ATL em um projeto MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Adicionando uma classe](../../ide/adding-a-class-visual-cpp.md)   
 [Adicionar uma função de membro](../../ide/adding-a-member-function-visual-cpp.md)   
 [Adicionar uma variável de membro](../../ide/adding-a-member-variable-visual-cpp.md)   
 [Substituindo uma função Virtual](../../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Manipulador de mensagens do MFC](../../mfc/reference/adding-an-mfc-message-handler.md)   
 [Navegando na estrutura de classe](../../ide/navigating-the-class-structure-visual-cpp.md)
