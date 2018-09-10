---
title: Adicionando informações de versão para outra linguagem (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.version
dev_langs:
- C++
helpviewer_keywords:
- languages, version information
- New Version Info Block
- blocks, adding
- resources [C++], adding version information
- version information, adding for languages
ms.assetid: 17f6273c-e1cc-441a-a3d8-f564341cbf20
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: bf01f1d4b1c687ed919b94f651ef7ccf4b0bf45d
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44313437"
---
# <a name="adding-version-information-for-another-language-c"></a>Adicionando informações de versão para outra linguagem (C++)

### <a name="to-add-version-information-for-another-language-new-info-block"></a>Para adicionar informações de versão para outro idioma (novo bloco de informações)

1. Abrir um recurso de informações de versão clicando duas vezes no [exibição de recurso](../windows/resource-view-window.md).

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. Clique dentro da tabela de informações de versão e escolha **novo bloco de informações de versão** no menu de atalho.

   Este comando adiciona um bloco de informações adicionais para o recurso de informações de versão atual e abre suas propriedades correspondentes na [janela de propriedades](/visualstudio/ide/reference/properties-window).

3. No **propriedades** janela, escolha o idioma apropriado e do conjunto para o novo bloco de caracteres.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de informações de versão](../windows/version-information-editor.md)  
[Informações de versão (Windows)](https://msdn.microsoft.com/library/windows/desktop/ms646981.aspx)