---
title: Páginas de propriedade da ferramenta geradora de documento XML
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCXDCMakeTool.ValidateIntelliSense
- VC.Project.VCXDCMakeTool.SuppressStartupBanner
- VC.Project.VCXDCMakeTool.DocumentLibraryDependencies
- VC.Project.VCXDCMakeTool.OutputDocumentFile
- VC.Project.VCXDCMakeTool.AdditionalDocumentFiles
ms.assetid: 645912b5-197a-4c36-ba58-64df09444ca0
ms.openlocfilehash: 9f10ddf98c238120750e72644779a6ad74af2d1e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171626"
---
# <a name="xml-document-generator-tool-property-pages"></a>Páginas de propriedade da ferramenta geradora de documento XML

A página de propriedades da Ferramenta de Gerador de Documento XML expõe a funcionalidade de xdcmake.exe. xdcmake.exe mescla arquivos .xdc em um arquivo .xml quando o código-fonte contém comentários da documentação e a opção [/doc (Processar Comentários da Documentação) (C/C++)](doc-process-documentation-comments-c-cpp.md) é especificada. Confira [Marcas recomendadas para comentários da documentação](recommended-tags-for-documentation-comments-visual-cpp.md) para obter informações sobre como adicionar comentários da documentação ao código-fonte.

> [!NOTE]
>  As opções de xdcmake.exe no ambiente de desenvolvimento (páginas de propriedades) são diferentes das opções exibidas quando xdcmake.exe é usado na linha de comando. Para obter informações sobre como usar xdcmake.exe na linha de comando, confira [Referência de XDCMake](xdcmake-reference.md).

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

- **Suprimir Faixa de Inicialização**

   Suprime uma mensagem de direitos autorais.

- **Arquivos de Documento Adicionais**

   Diretórios adicionais nos quais você deseja que o sistema de projeto procure arquivos .xdc. O xdcmake sempre procurará arquivos .xdc gerados pelo projeto. Podem ser especificados vários diretórios.

- **Arquivo de Documento de Saída**

   O nome e o local de diretório do arquivo de saída .xml. Consulte [macros comuns para criar comandos e propriedades](common-macros-for-build-commands-and-properties.md) para obter informações sobre como usar macros para especificar locais de diretório.

- **Dependências de biblioteca de documentos**

   Se o projeto tem uma dependência de um projeto .lib na solução, você pode processar arquivos .xdc do projeto .lib nos arquivos .xml do projeto atual.

## <a name="see-also"></a>Confira também

[C++referência de página de propriedades do projeto](property-pages-visual-cpp.md)
