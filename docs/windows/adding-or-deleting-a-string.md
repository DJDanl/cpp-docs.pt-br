---
title: Adicionando ou excluindo uma cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.string
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], adding to string tables
- string tables, deleting strings
- strings [C++], deleting in string tables
- string tables, adding strings
ms.assetid: 077077b4-0f4b-4633-92d6-60b321164cab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 952531a846fe48e9f093f016efd67d73c386d82c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43204481"
---
# <a name="adding-or-deleting-a-string"></a>Adicionando ou excluindo uma cadeia de caracteres

Você pode inserir rapidamente novas entradas para a tabela de cadeia de caracteres usando o **cadeia de caracteres** editor. Novas cadeias de caracteres são colocadas no final da tabela e recebem o próximo identificador disponível. Você pode editar, em seguida, o **ID**, **valor**, ou **legenda** propriedades no [janela propriedades](/visualstudio/ide/reference/properties-window) conforme necessário.

O **cadeia de caracteres** editor torna-se de que você não usar uma ID que já está em uso. Se você selecionar uma ID já em uso, o **cadeia de caracteres** editor de notificá-lo e, em seguida, atribuir uma ID exclusiva genérica, por exemplo `IDS_STRING58113`.

### <a name="to-add-a-string-table-entry"></a>Para adicionar uma entrada de tabela de cadeia de caracteres

1. Abra a tabela de cadeia de caracteres clicando duas vezes em seu ícone no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Clique dentro da tabela de cadeia de caracteres e escolha **nova cadeia de caracteres** no menu de atalho.

3. No **cadeia de caracteres** editor, selecione um **ID** na lista de IDs de lista suspensa ou digitar um ID diretamente in-loco.

4. Editar o **valor**, se necessário.

5. Digite uma entrada para o **legenda**.

   > [!NOTE]
   > Cadeias de caracteres nulas não são permitidas em tabelas de cadeia de caracteres do Windows. Se você criar uma entrada na tabela de cadeia de caracteres que é uma cadeia de caracteres nula, você receberá uma mensagem pedindo para "Insira uma cadeia de caracteres para esta entrada de tabela."

### <a name="to-delete-a-string-table-entry"></a>Para excluir uma entrada de tabela de cadeia de caracteres

1. Selecione a entrada que você deseja excluir.

2. Sobre o **edite** menu, clique em **excluir**.

\- ou -

- Com a cadeia de caracteres que você deseja excluir e escolha o botão direito **excluir** no menu de atalho.

\- ou -

- Pressione a **excluir** chave.

Para obter informações sobre como adicionar recursos a projetos gerenciados (aquelas que visam o common language runtime), consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recursos a propriedades, consulte [instruções passo a passo: Localizando Windows Forms](/previous-versions/visualstudio/visual-studio-2010/y99d1cd3\(v=vs.100\)).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de cadeias de caracteres](../windows/string-editor.md)  