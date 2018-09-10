---
title: 'Como: criar um arquivo de Script de recurso (C++) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- rc files [C++], creating
- .rc files [C++], creating
- resource script files [C++], creating
ms.assetid: 82be732a-cdcd-4a58-8de7-976d1418f86b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 092cb7c33aab2805ca40410cac404d43ba5c9274
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44313230"
---
# <a name="how-to-create-a-resource-script-file-c"></a>Como: criar um arquivo de Script de recurso (C++)

> [!NOTE]
> O **Editor de recurso** não está disponível nas edições Express.
>
> Este material se aplica a aplicativos de área de trabalho do Windows. Projetos em linguagens .NET não usem arquivos de script de recurso. Ver [arquivos de recurso](../windows/resource-files-visual-studio.md), para obter mais informações.

### <a name="to-create-a-new-resource-script-rc-file"></a>Para criar um novo arquivo de script (. rc) do recurso

1. Colocar o foco na sua pasta de projeto existente no **Gerenciador de soluções**, por exemplo, `MyProject`.

   > [!NOTE]
   > Não confunda a pasta do projeto com a pasta da solução no **Gerenciador de soluções**. Se você colocar o foco a **solução** pasta, suas escolhas no **Adicionar Novo Item** caixa de diálogo (na etapa 3) será diferente.

2. No menu **Projeto**, clique em **Adicionar Novo Item**.

3. No **Adicionar Novo Item** caixa de diálogo, clique o **Visual C++** pasta, em seguida, escolha **arquivo de recurso (. rc)** no painel direito.

4. Forneça um nome para seu arquivo de script de recurso nas **nome** texto caixa e, em seguida, clique em **abrir**.

Agora você pode [criar](../windows/how-to-create-a-resource.md) e adicionar novos recursos ao seu arquivo. rc.

> [!NOTE]
> Você só pode adicionar um script de recurso (arquivo. rc) a um projeto existente que é carregado no IDE do Visual Studio. Você não pode criar um arquivo. rc autônomo (fora do projeto um). [Modelos de recursos](../windows/how-to-use-resource-templates.md) (arquivos. rct) podem ser criados a qualquer momento.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editores de recursos](../windows/resource-editors.md)