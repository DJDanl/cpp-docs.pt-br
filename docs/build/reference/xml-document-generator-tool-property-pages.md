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
ms.openlocfilehash: d17913909532c5bebcac712937af00be3ad98712
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335761"
---
# <a name="xml-document-generator-tool-property-pages"></a>Páginas de propriedade da ferramenta geradora de documento XML

A página de propriedades da Ferramenta de Gerador de Documento XML expõe a funcionalidade de xdcmake.exe. xdcmake.exe mescla arquivos .xdc em um arquivo .xml quando o código-fonte contém comentários da documentação e a opção [/doc (Processar Comentários da Documentação) (C/C++)](doc-process-documentation-comments-c-cpp.md) é especificada. Confira [Marcas recomendadas para comentários da documentação](recommended-tags-for-documentation-comments-visual-cpp.md) para obter informações sobre como adicionar comentários da documentação ao código-fonte.

> [!NOTE]
> As opções de xdcmake.exe no ambiente de desenvolvimento (páginas de propriedades) são diferentes das opções exibidas quando xdcmake.exe é usado na linha de comando. Para obter informações sobre como usar xdcmake.exe na linha de comando, confira [Referência de XDCMake](xdcmake-reference.md).

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

- **Suprimir Faixa de Inicialização**

   Suprime uma mensagem de direitos autorais.

- **Arquivos de Documento Adicionais**

   Diretórios adicionais nos quais você deseja que o sistema de projeto procure arquivos .xdc. O xdcmake sempre procurará arquivos .xdc gerados pelo projeto. Podem ser especificados vários diretórios.

- **Arquivo de Documento de Saída**

   O nome e o local de diretório do arquivo de saída .xml. Consulte [as macros comuns para criar comandos e propriedades](common-macros-for-build-commands-and-properties.md) para obter informações sobre o uso de macros para especificar locais de diretório.

- **Dependências de biblioteca de documentos**

   Se o projeto tem uma dependência de um projeto .lib na solução, você pode processar arquivos .xdc do projeto .lib nos arquivos .xml do projeto atual.

## <a name="see-also"></a>Confira também

[Referência da página de propriedade do projeto C++](property-pages-visual-cpp.md)
