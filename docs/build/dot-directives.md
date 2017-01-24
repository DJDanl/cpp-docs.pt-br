---
title: "Diretivas de ponto | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "diretivas dot em NMAKE"
  - "programa NMAKE, diretivas dot"
ms.assetid: ab35da65-30b6-48b7-87d6-61503d7faf9f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas de ponto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especificar políticas de ponto fora de um bloco de descrição, no início de uma linha.  As políticas de ponto começam com um ponto \(. \) e são seguidas por dois\-pontos \(:\).  Espaços e as guias são permitidos.  Os nomes diretiva de ponto diferenciam maiúsculas de minúsculas e estão em maiúsculas.  
  
|Diretiva|Finalidade|  
|--------------|----------------|  
|**.IGNORE:**|Ignora os códigos de saída diferentes de zero retornados por comandos, no local especificado ao final de makefile.  Por padrão, NMAKE é interrompida se um comando retorna um código de saída diferente de zero.  Para restaurar verificação de erros, use **\!CMDSWITCHES**.  Para ignorar o código de saída de um único comando, use o modificador de traço \(–\).  Para ignorar códigos de saída para um arquivo inteiro, use a \/I.|  
|*destinos de* **.PRECIOUS :**|*Destinos* de preserva em disco se os comandos a atualização são paralisados; não tem nenhum efeito se um comando manipula uma interrupção excluindo o arquivo.  Separe os nomes de destino com um ou mais espaços ou guias.  Por padrão, NMAKE exclui um destino se uma construção é interrompida por CTRL\+C ou por CTRL\+BREAK.  Cada uso de **.PRECIOUS** se aplica ao makefile inteiro; várias especificações são cumulativos.|  
|**.SILENT:**|Suprime a exibição de comandos executados, no local especificado ao final de makefile.  Por padrão, NMAKE exibe os comandos que invoca.  Para restaurar o eco, use **\!CMDSWITCHES**.  Para suprimir o eco de um único comando, use o modificador de **@** .  Para suprimir o eco para um arquivo inteiro, use a \/S.|  
|**.SUFFIXES :** `list`|Lista as extensões para a correspondência de inferência\- regra; predefinido para incluir as seguintes extensões: .exe .obj .asm .c .cpp .cxx .bas .cbl .for .pas .res .rc .f .f90|  
  
 Para alterar a ordem da lista de **.SUFFIXES** ou especificar uma nova lista, limpe a lista e especifique uma nova configuração.  Para limpar a lista, não especificar uma extensão após os dois\-pontos:  
  
```  
.SUFFIXES :  
```  
  
 Para adicionar sufixos adicionais ao final da lista, especifique  
  
```  
.SUFFIXES : suffixlist  
```  
  
 no *suffixlist* é uma lista dos sufixos adicionais, separadas por um ou mais espaços ou guias.  Para visualizar a configuração atual de **.SUFFIXES**, execute NMAKE com \/P.  
  
## Consulte também  
 [Referência de NMAKE](../build/nmake-reference.md)