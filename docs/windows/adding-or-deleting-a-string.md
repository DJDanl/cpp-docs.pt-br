---
title: Adicionando ou excluindo uma cadeia de caracteres | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.string
dev_langs: C++
helpviewer_keywords:
- strings [C++], adding to string tables
- string tables, deleting strings
- strings [C++], deleting in string tables
- string tables, adding strings
ms.assetid: 077077b4-0f4b-4633-92d6-60b321164cab
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0e485e1c689814e63c5a43edba2ded80967d576a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-or-deleting-a-string"></a>Adicionando ou excluindo uma cadeia de caracteres
Você pode inserir rapidamente novas entradas na tabela de cadeia de caracteres usando o editor de cadeia de caracteres. Novas cadeias de caracteres são colocadas no final da tabela e recebem o próximo identificador disponível. Você pode editar as propriedades de ID, o valor ou a legenda no [janela propriedades](/visualstudio/ide/reference/properties-window) conforme necessário.  
  
 O editor de cadeia de caracteres torna-se de que você não usa uma ID que já está em uso. Se você selecionar uma ID já em uso, o editor de cadeia de caracteres notificá-lo e, em seguida, atribuir uma ID exclusiva genérica, por exemplo IDS_STRING58113.  
  
### <a name="to-add-a-string-table-entry"></a>Para adicionar uma entrada de tabela de cadeia de caracteres  
  
1.  Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição recursos](../windows/resource-view-window.md).  
  
    > [!NOTE]
    >  Se o projeto já não contiver um arquivo. RC, consulte [criar um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).  
  
2.  Clique dentro da tabela de cadeia de caracteres e escolha **nova cadeia de caracteres** no menu de atalho.  
  
3.  No **cadeia de caracteres** editor, selecione um **ID** na lista suspensa ou digite um local diretamente no ID.  
  
4.  Editar o **valor**, se necessário.  
  
5.  Digite uma entrada para o **legenda**.  
  
    > [!NOTE]
    >  Cadeias de caracteres nulas não são permitidas em tabelas de cadeia de caracteres do Windows. Se você criar uma entrada na tabela de cadeia de caracteres que é uma cadeia de caracteres nula, você receberá uma mensagem pedindo para "Insira uma cadeia de caracteres para esta entrada de tabela."  
  
### <a name="to-delete-a-string-table-entry"></a>Para excluir uma entrada de tabela de cadeia de caracteres  
  
1.  Selecione a entrada que você deseja excluir.  
  
2.  Sobre o **editar** menu, clique em **excluir**.  
  
 \- ou -  
  
-   Clique com botão direito a cadeia de caracteres que você deseja excluir e escolha **excluir** no menu de atalho.  
  
 \- ou -  
  
-   Pressione a **excluir** chave.  
  
 Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que se destinam a common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) no *guia do desenvolvedor do .NET Framework.* Para obter informações sobre como adicionar manualmente os arquivos de recurso para projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos para propriedades, consulte [passo a passo: Localizando Windows Forms](http://msdn.microsoft.com/en-us/9a96220d-a19b-4de0-9f48-01e5d82679e5) e [Passo a passo: usando recursos para localização com o ASP.NET](http://msdn.microsoft.com/Library/bb4e5b44-e2b0-48ab-bbe9-609fb33900b6).  
  
 **Requisitos**  
  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Editor de cadeias de caracteres](../windows/string-editor.md)   

