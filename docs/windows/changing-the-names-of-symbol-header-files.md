---
title: Alterando os nomes de arquivos de cabeçalho de símbolo
ms.date: 11/04/2016
f1_keywords:
- vc.editors.symbol.changing.header
helpviewer_keywords:
- resource files [C++], multiple
- Resource Includes dialog box [C++]
- symbol header files [C++], changing names
- symbols [C++], symbol header files
- Resource.h
ms.assetid: b948284a-7899-402e-ab12-9f2c8480ca9d
ms.openlocfilehash: 4d9aa350d0f680e975c68bf46ac066072df044cb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432325"
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

[Exibindo símbolos de recurso](../windows/viewing-resource-symbols.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)