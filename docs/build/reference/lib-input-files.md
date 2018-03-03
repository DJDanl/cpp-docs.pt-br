---
title: Arquivos de entrada LIB | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Lib
dev_langs:
- C++
helpviewer_keywords:
- input files, LIB
ms.assetid: e1236f0d-cd90-446b-b900-f311f456085c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5fea7a8700eb2f5a5deee7afd05af8b0de0e4e71
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="lib-input-files"></a>Arquivos de entrada LIB
Os arquivos de entrada esperados pelo LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.  
  
|Modo|Entrada|  
|----------|-----------|  
|Padrão (Criando ou modificando uma biblioteca)|Arquivos de objeto (. obj) COFF, bibliotecas COFF (. lib), arquivos de objeto (. obj) do formato de modelo de objeto (OMF) de 32 bits|  
|Extraindo um membro com /EXTRACT|Biblioteca COFF (. lib)|  
|Criar uma exportação de arquivo e importar biblioteca com /DEF|Arquivo de definição de módulo (. def), arquivos de objeto (. obj) COFF, bibliotecas COFF (. lib), arquivos de objeto (. obj) OMF 32 bits|  
  
> [!NOTE]
>  Bibliotecas OMF criadas pela versão de 16 bits de LIB não podem ser usadas como entrada para a versão de 32 bits do LIB.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)