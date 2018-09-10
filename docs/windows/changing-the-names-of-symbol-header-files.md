---
title: Alterar os nomes dos arquivos de cabeçalho de símbolo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.symbol.changing.header
dev_langs:
- C++
helpviewer_keywords:
- resource files [C++], multiple
- Resource Includes dialog box [C++]
- symbol header files [C++], changing names
- symbols [C++], symbol header files
- Resource.h
ms.assetid: b948284a-7899-402e-ab12-9f2c8480ca9d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 587cc5315395a58e6fdeb01929f920f506031e58
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44317388"
---
# <a name="changing-the-names-of-symbol-header-files"></a>Alterando os nomes de arquivos de cabeçalho de símbolo

Normalmente, todos os símbolos definições são salvos no `Resource.h`. No entanto, talvez você precise alterar isso incluir o nome de arquivo para que você pode, por exemplo, trabalhar com mais de um arquivo de recurso no mesmo diretório.

### <a name="to-change-the-name-of-the-resource-symbol-header-file"></a>Para alterar o nome do arquivo de cabeçalho de símbolo de recurso

1. Na [exibição de recurso](../windows/resource-view-window.md), clique com botão direito seu arquivo. RC e escolha [recurso inclui](../windows/resource-includes-dialog-box.md) no menu de atalho.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No **arquivo de cabeçalho de símbolo** , digite o novo nome para o arquivo de inclusão.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)  
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)