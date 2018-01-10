---
title: "Referência XDCMake | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xdcmake
dev_langs: C++
helpviewer_keywords: xdcmake program
ms.assetid: 14e65747-d000-4343-854b-8393bf01cbac
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea635d701b4dea2471067072083d9568f11f3d82
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="xdcmake-reference"></a>Referência XDCMake
xdcmake.exe é um programa que compila arquivos. XDC em um arquivo. XML. Um arquivo. XDC é criado pelo compilador do Visual C++ para cada arquivo de código fonte quando o código-fonte é compilado com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) e quando o arquivo de código fonte contém comentários de documentação marcados com marcas XML.  
  
### <a name="to-use-xdcmakeexe-in-the-visual-studio-development-environment"></a>Para usar xdcmake.exe no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
2.  Abra o **propriedades de configuração** pasta.  
  
3.  Clique o **comentários de documento XML** página de propriedades.  
  
> [!NOTE]
>  Opções de xdcmake.exe na linha de comando diferirem das opções quando xdcmake.exe é usado no ambiente de desenvolvimento (páginas de propriedade). Para obter informações sobre como usar xdcmake.exe no ambiente de desenvolvimento, consulte [páginas de propriedades ferramenta do gerador de documento XML](../ide/xml-document-generator-tool-property-pages.md).  
  
## <a name="syntax"></a>Sintaxe  
 xdcmake`input_filename options`  
  
## <a name="parameters"></a>Parâmetros  
 em que:  
  
 `input_filename`  
 O nome de arquivo dos arquivos. XDC usados como entrada para xdcmake.exe. Especifique um ou mais arquivos. XDC ou use *.xdc para usar todos os arquivos. XDC no diretório atual.  
  
 `options`  
 Zero ou mais dos seguintes:  
  
|Opção|Descrição|  
|------------|-----------------|  
|/?, /Help|Exibir a Ajuda para xdcmake.exe.|  
|/assembly:*filename*|Permite que você especifique o valor de \<assembly > marca no arquivo. XML.  Por padrão, o valor de \<assembly > marca é o mesmo que o nome do arquivo. XML.|  
|/nologo|Suprima a mensagem de direitos autorais.|  
|/out:*filename*|Permite que você especifique o nome do arquivo. XML.  Por padrão, o nome do arquivo. XML é o nome do arquivo. XDC primeiro processado pelo xdcmake.exe.|  
  
## <a name="remarks"></a>Comentários  
 O Visual Studio invocará xdcmake.exe automaticamente ao criar um projeto. Você também pode invocar xdcmake.exe na linha de comando.  
  
 Consulte [marcas recomendadas para comentários de documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md) para obter mais informações sobre como adicionar comentários de documentação para os arquivos de código fonte.  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)