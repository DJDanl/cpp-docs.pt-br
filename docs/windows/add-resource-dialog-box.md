---
title: Adicionar caixa de diálogo recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.insertresource
dev_langs:
- C++
helpviewer_keywords:
- resources [Visual Studio], adding
- Add Resource dialog box
ms.assetid: e9fb6967-738f-47e8-ab58-728cf35b3af0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a48b99ad1d00fdcc184f6a3fadc772b32057f75d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42601324"
---
# <a name="add-resource-dialog-box"></a>Caixa de diálogo Adicionar Recurso

Use essa caixa de diálogo para adicionar recursos a um projeto de aplicativo da área de trabalho do Windows C++.

> [!NOTE]
> Essas informações não se aplica a recursos em aplicativos da plataforma Universal do Windows. Para obter mais informações sobre isso, consulte [recursos do aplicativo e o sistema de gerenciamento de recursos](/windows/uwp/app-resources/).

### <a name="resource-type"></a>Tipo de recurso

Especifica o tipo de recurso que você deseja criar.

Você pode expandir as categorias de recursos de caixa de cursor e a caixa de diálogo para revelar os recursos adicionais. Esses recursos estão localizados no Visual Studio de ...\Microsoft `version`\VC\VCResourceTemplates\\< LCID\>\mfc.rct. Se você adicionar arquivos. rct, você deve colocá-los neste diretório ou você deve especificar um [caminho de inclusão](../windows/how-to-specify-include-directories-for-resources.md) para eles. Os recursos nesses arquivos, em seguida, aparecem no segundo nível sob a categoria apropriada. Não há nenhum limite predefinido para o número de arquivos. rct que você pode adicionar.

Os recursos mostrados no nível superior no controle de árvore são os recursos padrão que são fornecidos pelo Visual Studio.

### <a name="new"></a>Novo

Cria um recurso com base no tipo que você selecionou a **tipo de recurso** caixa. O recurso é aberto no editor apropriado. Por exemplo, se você criar um recurso de caixa de diálogo, ele abre na [editor de caixa de diálogo](../windows/dialog-editor.md).

### <a name="import"></a>Importar

Abre o **importação** caixa de diálogo na qual você pode navegar para um recurso você deseja importar para seu projeto atual. Você pode importar um bitmap, o ícone, o cursor, o arquivo de recurso do HTML, som (. Arquivo de recurso WAV) ou arquivo de recurso personalizado.

### <a name="custom"></a>Personalizado

Abre o [caixa de diálogo novo recurso personalizado](../windows/new-custom-resource-dialog-box.md) no qual você pode criar um recurso personalizado. Recursos personalizados podem ser editados no editor binário.

## <a name="requirements"></a>Requisitos

Nenhum

## <a name="see-also"></a>Consulte também

[Como criar um recurso](../windows/how-to-create-a-resource.md)