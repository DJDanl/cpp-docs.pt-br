---
title: Criar uma caixa de diálogo (C++) que os usuários não possam sair | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes [C++], creating
- modal dialog boxes [C++], logon screens
- logon screens
ms.assetid: 54823c27-1658-4388-bd12-0a1ce8f3899e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: f0b9c290cb8e5ced7537fb377d6e7ac52f20d089
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44314541"
---
# <a name="creating-a-dialog-box-c-that-users-cannot-exit"></a>Criando uma caixa de diálogo (C++) que os usuários não possam sair

Você pode criar uma caixa de diálogo de tempo de execução que um usuário não pode sair. Esse tipo de caixa de diálogo é útil para logons e para bloqueios de documento ou aplicativo.

### <a name="to-create-a-dialog-box-that-a-user-cannot-exit"></a>Para criar uma caixa de diálogo que um usuário não possam sair

1. No **propriedades** painel para a caixa de diálogo, defina as **Menu do sistema** propriedade a ser **false**.

   Isso desabilita o menu de sistema de caixa de diálogo e **fechar** botão.

2. No formulário de caixa de diálogo, exclua o **cancele** e **Okey** botões.

   Em tempo de execução, um usuário não pode sair de uma caixa de diálogo modal que tem as seguintes características.

Para habilitar o teste desse tipo de caixa de diálogo, a função de caixa de diálogo test detecta quando **Esc** é pressionado. (**Esc** também é conhecido como a chave de virtual VK_ESCAPE.) Não importa como a caixa de diálogo é projetada para se comportar em tempo de execução, você pode encerrá-lo no modo de teste pressionando **Esc**.

> [!NOTE]
> Para aplicativos do MFC para criar uma caixa de diálogo que os usuários não possam sair, você deve substituir o comportamento padrão do `OnOK` e `OnCancel` porque, mesmo se você excluir os botões associados, a caixa de diálogo ainda pode ser descartada, pressionando  **Insira** ou **Esc**.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Como criar um recurso](../windows/how-to-create-a-resource.md)  
[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editor de caixa de diálogo](../windows/dialog-editor.md)