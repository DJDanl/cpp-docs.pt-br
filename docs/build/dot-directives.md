---
title: Diretivas de ponto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, dot directives
- dot directives in NMAKE
ms.assetid: ab35da65-30b6-48b7-87d6-61503d7faf9f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9958b13a6f06b0024ec2d4dd304abfe93b16741e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dot-directives"></a>Diretivas de ponto
Especifica diretivas dot fora de um bloco de descrição, no início de uma linha. Diretivas dot começam com um ponto (. ) e são seguidos por dois-pontos (:). São permitidas espaços e guias. Nomes de diretiva ponto diferenciam maiusculas de minúsculas e maiusculas.  
  
|Diretiva|Finalidade|  
|---------------|-------------|  
|**. IGNORE:**|Ignora códigos de saída diferente de zero retornados por comandos do local especificado para o fim do makefile. Por padrão, NMAKE é interrompida se um comando retorna um código de saída diferente de zero. Para restaurar a verificação de erros, use **! CMDSWITCHES**. Para ignorar o código de saída de um único comando, use o modificador de traço (-). Para ignorar os códigos de saída para um arquivo inteiro, use / I.|  
|**. PRECIOSOS:** *destinos*|Preserva *destinos* em disco se os comandos para atualizá-los são interrompidos; não tem nenhum efeito se um comando trata de uma interrupção, excluindo o arquivo. Separe os nomes de destino com um ou mais espaços ou guias. Por padrão, NMAKE exclui um destino se uma compilação é interrompida por CTRL + C ou CTRL + BREAK. Cada uso de **. PRECIOSOS** se aplica a todo makefile; várias especificações são cumulativas.|  
|**. SILENCIOSO:**|Suprime a exibição de comandos executados, no local especificado para o fim do makefile. Por padrão, NMAKE exibe os comandos que ele chama. Para restaurar a repetição, use **! CMDSWITCHES**. Para suprimir o eco de um único comando, use o  **@**  modificador. Para suprimir o eco de um arquivo inteiro, use/s.|  
|**. SUFIXOS:**`list`|Lista de extensões para a regra de inferência correspondência; predefinidas incluem as seguintes extensões: .exe. obj. ASM. c. cpp. cxx. BAS. cbl .for. PAS. res. rc .f .f90|  
  
 Para alterar o **. SUFIXOS** lista ordem ou para especificar uma nova lista, limpe a lista e especificar uma nova configuração. Para limpar a lista, não especifique nenhuma extensão após os dois-pontos:  
  
```  
.SUFFIXES :  
```  
  
 Para adicionar sufixos adicionais ao final da lista, especifique  
  
```  
.SUFFIXES : suffixlist  
```  
  
 onde *suffixlist* é uma lista dos sufixos adicionais, separados por um ou mais espaços ou guias. Para ver a configuração atual de **. SUFIXOS**, execute NMAKE com /P.  
  
## <a name="see-also"></a>Consulte também  
 [Referência a NMAKE](../build/nmake-reference.md)