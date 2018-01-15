---
title: "-Fi (pré-processar nome do arquivo de saída) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /Fi
dev_langs: C++
helpviewer_keywords:
- Fi compiler option (C++)
- -Fi compiler option (C++)
- /Fi compiler option (C++)
- preprocessing output files, file name
ms.assetid: 6d0ba983-a8b7-41ec-84f5-b4688ef8efee
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9bc3076a529984358aed16902f509ceb01423f9e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fi-preprocess-output-file-name"></a>/Fi (pré-processar nome do arquivo de saída)
Especifica o nome do arquivo de saída para o qual o [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md) opção de compilador grava saída pré-processada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Fipathname  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`pathname`|O nome e caminho do arquivo de saída produzido pelo **/p** opção de compilador.|  
  
## <a name="remarks"></a>Comentários  
 Use o **/Fi** opção de compilador em combinação com o **/p** opção de compilador.  
  
 Se você especificar apenas um caminho para o `pathname` parâmetro, o nome base do arquivo de origem é usado como o nome base do arquivo de saída pré-processada. O `pathname` parâmetro não exige uma extensão de nome de arquivo específico. No entanto, uma extensão de ".i" será usada se você não especificar uma extensão de nome de arquivo.  
  
## <a name="example"></a>Exemplo  
 A seguinte linha de comando pré-processa PROGRAM.cpp, preserva comentários, adiciona [#line](../../preprocessor/hash-line-directive-c-cpp.md) diretivas e grava o resultado para o arquivo MYPROCESS.i.  
  
```  
CL /P /FiMYPROCESS.I PROGRAM.CPP  
```  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md)   
 [Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)