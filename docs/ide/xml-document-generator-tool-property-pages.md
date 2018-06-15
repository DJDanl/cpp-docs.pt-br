---
title: Páginas de propriedades da Ferramenta de Gerador de Documento XML | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCXDCMakeTool.ValidateIntelliSense
- VC.Project.VCXDCMakeTool.SuppressStartupBanner
- VC.Project.VCXDCMakeTool.DocumentLibraryDependencies
- VC.Project.VCXDCMakeTool.OutputDocumentFile
- VC.Project.VCXDCMakeTool.AdditionalDocumentFiles
dev_langs:
- C++
ms.assetid: 645912b5-197a-4c36-ba58-64df09444ca0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 772e9dc6a296873ef27171676ebca0c185c1771c
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33339070"
---
# <a name="xml-document-generator-tool-property-pages"></a>Páginas de propriedade da ferramenta geradora de documento XML
A página de propriedades da Ferramenta de Gerador de Documento XML expõe a funcionalidade de xdcmake.exe. xdcmake.exe mescla arquivos .xdc em um arquivo .xml quando o código-fonte contém comentários da documentação e a opção [/doc (Processar Comentários da Documentação) (C/C++)](../build/reference/doc-process-documentation-comments-c-cpp.md) é especificada. Confira [Marcas recomendadas para comentários da documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md) para obter informações sobre como adicionar comentários da documentação ao código-fonte.  
  
> [!NOTE]
>  As opções de xdcmake.exe no ambiente de desenvolvimento (páginas de propriedades) são diferentes das opções exibidas quando xdcmake.exe é usado na linha de comando. Para obter informações sobre como usar xdcmake.exe na linha de comando, confira [Referência de XDCMake](../ide/xdcmake-reference.md).  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Suprimir Faixa de Inicialização**  
 Suprime uma mensagem de direitos autorais.  
  
 **Arquivos de Documento Adicionais**  
 Diretórios adicionais nos quais você deseja que o sistema de projeto procure arquivos .xdc. O xdcmake sempre procurará arquivos .xdc gerados pelo projeto. Podem ser especificados vários diretórios.  
  
 **Arquivo de Documento de Saída**  
 O nome e o local de diretório do arquivo de saída .xml. Confira [Macros comuns para comandos e propriedades de build](../ide/common-macros-for-build-commands-and-properties.md) para obter informações sobre como usar macros para especificar locais de diretório.  
  
 **Dependências de biblioteca de documentos**  
 Se o projeto tem uma dependência de um projeto .lib na solução, você pode processar arquivos .xdc do projeto .lib nos arquivos .xml do projeto atual.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedades](../ide/property-pages-visual-cpp.md)   
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)