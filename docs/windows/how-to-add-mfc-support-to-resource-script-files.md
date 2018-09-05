---
title: 'Como: adicionar suporte MFC aos arquivos de Script de recurso | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.resvw.add.MFC
dev_langs:
- C++
helpviewer_keywords:
- rc files, adding MFC support
- .rc files, adding MFC support
- MFC, adding support to resource scripts files
- resource script files, adding MFC support
ms.assetid: 599dfe9d-ad26-4e34-899c-49b56599e37f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 194f2b4f2e6659412c9c2b5f688e0b73eea3bba5
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43692022"
---
# <a name="how-to-add-mfc-support-to-resource-script-files"></a>Como adicionar suporte MFC a arquivos de script de recurso

Normalmente, quando você cria um aplicativo MFC para Windows usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), o assistente gera um conjunto básico de arquivos (incluindo um arquivo de script (. rc) do recurso) que contém os principais recursos do Microsoft Foundation classes (MFC). No entanto, se você estiver editando um arquivo. RC para um aplicativo do Windows que não é baseado no MFC, os seguintes recursos específicos da estrutura MFC não estão disponíveis:

- Assistentes de código do MFC

- Cadeias de caracteres de prompt do menu

- Listar o conteúdo para controles de caixa de combinação

- Hospedagem de controles ActiveX

No entanto, você pode adicionar suporte MFC aos arquivos. rc existentes que não têm.

### <a name="to-add-mfc-support-to-rc-files"></a>Para adicionar suporte MFC aos arquivos. rc

1. Abra o arquivo de script de recurso.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Na [exibição de recurso](../windows/resource-view-window.md), realce a pasta de recursos (por exemplo, RC).

3. No [janela de propriedades](/visualstudio/ide/reference/properties-window), defina o **modo MFC** propriedade a ser **verdadeiro**.

   > [!NOTE]
   > Além de definir esse sinalizador, o arquivo. rc deve fazer parte de um projeto MFC. Por exemplo, apenas configurando **modo MFC** à **verdadeiro** em um arquivo. rc em Win32 project não dará os recursos do MFC.

## <a name="requirements"></a>Requisitos

MFC

## <a name="see-also"></a>Consulte também

[Arquivos de recurso](../windows/resource-files-visual-studio.md)  
[Editores de recursos](../windows/resource-editors.md)