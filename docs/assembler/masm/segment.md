---
title: "SEGMENT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "SEGMENT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "SEGMENT directive"
ms.assetid: e6f68367-6714-4f06-a79c-edfa88014430
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# SEGMENT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um segmento do programa chamado  *nome* têm atributos de segmento  
  
## Sintaxe  
  
```  
  
   name SEGMENT [[READONLY]] [[align]] [[combine]] [[use]] [[characteristics]] ALIAS(string) [['class']]  
statements  
name ENDS  
```  
  
#### Parâmetros  
 *Alinhar*  
 O intervalo de endereços de memória na qual um endereço inicial do segmento pode ser selecionado.  O tipo de alinhamento pode ser qualquer um dos seguintes procedimentos:  
  
|Alinhar o texto|Endereço inicial|  
|---------------------|----------------------|  
|**BYTE**|Endereço do próximo byte disponíveis.|  
|**WORD**|Endereço do word disponíveis próximo \(2 bytes por palavra\).|  
|**DWORD**|Endereço de próximo palavra de dupla disponíveis \(4 bytes por palavra dupla\).|  
|**PARA**|Endereço do próximo parágrafo disponíveis \(16 bytes por parágrafo\).|  
|**PÁGINA**|Próximo endereço de página disponíveis \(256 bytes por página\).|  
|**ALIGN**\(*n*\)|Próxima disponível  *n*endereço de bytes th.  Consulte a seção de comentários para obter mais informações.|  
  
 Se este parâmetro não for especificado,  **PARA** é usado por padrão.  
  
 *combinar*  
 **PUBLIC**, **STACK**, **COMMON**, **MEMORY**, **AT***address*, **PRIVATE**  
  
 *Use*  
 **USE16**, **USE32**, **FLAT**  
  
 `characteristics`  
 **INFO**, **READ**, **WRITE**, **EXECUTE**, **SHARED**, **NOPAGE**, **NOCACHE**, and **DISCARD**  
  
 Essas são suportadas apenas para COFF e correspondem às características COFF seção de nome semelhante \(por exemplo,  **SHARED** corresponde a IMAGE\_SCN\_MEM\_SHARED\).  LEITURA define o sinalizador IMAGE\_SCN\_MEM\_READ.  O sinalizador de somente leitura obsoleto causou a seção para limpar o sinalizador IMG\_SCN\_MEM\_WRITE.  Se houver `characteristics` são configurados, as características padrão não são usadas e somente os sinalizadores especificados pelo programador estão em vigor.  
  
 `ALIAS(` `string` `)`  
 Essa seqüência é usada como o nome da seção no objeto COFF emitido.  Cria várias seções com o mesmo nome externo, com nomes de segmento MASM distintas.  
  
 Não compatível com o **\/omf**.  
  
 `class`  
 Designa como segmentos devem ser combinados e ordenados no arquivo montado.  Typical values are, `'DATA'`, `'CODE'`, `'CONST'` and`'STACK'`  
  
## Comentários  
 For `ALIGN(``n``)`, `n` may be any power of 2 from 1 to 8192; não é suportado com **\/omf**.  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)