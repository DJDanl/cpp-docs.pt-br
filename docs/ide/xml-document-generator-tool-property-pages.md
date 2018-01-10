---
title: "Páginas de propriedades ferramenta do gerador de documento XML | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCXDCMakeTool.ValidateIntelliSense
- VC.Project.VCXDCMakeTool.SuppressStartupBanner
- VC.Project.VCXDCMakeTool.DocumentLibraryDependencies
- VC.Project.VCXDCMakeTool.OutputDocumentFile
- VC.Project.VCXDCMakeTool.AdditionalDocumentFiles
dev_langs: C++
ms.assetid: 645912b5-197a-4c36-ba58-64df09444ca0
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bc09dafc0f07bc16a11dd255419440b6464456c5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="xml-document-generator-tool-property-pages"></a>Páginas de propriedade da ferramenta geradora de documento XML
A página de propriedades ferramenta de gerador de documento XML expõe a funcionalidade de xdcmake.exe. xdcmake.exe mescla os arquivos. XDC em um arquivo. XML ao seu código-fonte contém comentários de documentação e [/doc (processar comentários de documentação) (C/C++)](../build/reference/doc-process-documentation-comments-c-cpp.md) for especificado,. Consulte [marcas recomendadas para comentários de documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md) para obter informações sobre como adicionar comentários de documentação no código-fonte.  
  
> [!NOTE]
>  Opções de xdcmake.exe no ambiente de desenvolvimento (páginas de propriedade) diferirem das opções quando xdcmake.exe é usada na linha de comando. Para obter informações sobre como usar xdcmake.exe na linha de comando, consulte [referência XDCMake](../ide/xdcmake-reference.md).  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Suprimir faixa de inicialização**  
 Suprima a mensagem de direitos autorais.  
  
 **Arquivos adicionais de documento**  
 Diretórios adicionais no qual você deseja que o sistema de projeto para procurar por arquivos. XDC. xdcmake sempre irá procurar por arquivos. XDC gerados pelo projeto. Podem ser especificados vários diretórios.  
  
 **Arquivo de documento de saída**  
 O local de diretório e nome do arquivo de saída. XML. Consulte [comuns Macros para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md) para obter informações sobre como usar macros para especificar locais de diretório.  
  
 **Dependências de biblioteca de documentos**  
 Se o projeto tiver uma dependência em um projeto. lib na solução, você pode processar arquivos. XDC do projeto. lib nos arquivos. XML para o projeto atual.  
  
## <a name="see-also"></a>Consulte também  
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)   
 [Páginas de propriedade](../ide/property-pages-visual-cpp.md)