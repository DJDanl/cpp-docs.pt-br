---
title: SEGMENTO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- SEGMENT
dev_langs:
- C++
helpviewer_keywords:
- SEGMENT directive
ms.assetid: e6f68367-6714-4f06-a79c-edfa88014430
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c55416cc5a757128c9cc97b2f342953911ac2946
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32058105"
---
# <a name="segment"></a>SEGMENT
Define um segmento de programa chamado *nome* ter atributos de segmento  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
   name SEGMENT [[READONLY]] [[align]] [[combine]] [[use]] [[characteristics]] ALIAS(string) [['class']]  
statements  
name ENDS  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *align*  
 O intervalo de endereços de memória do qual pode ser selecionado um endereço inicial do segmento. O tipo de alinhamento pode ser qualquer um dos seguintes:  
  
|Alinhar o texto|Endereço inicial|  
|----------------|----------------------|  
|**BYTE**|Próximo endereço de bytes disponíveis.|  
|**WORD**|Próximo endereço disponível word (2 bytes por palavra).|  
|**DWORD**|Próximo endereço de palavra de dupla disponível (4 bytes por palavra dupla).|  
|**PARA**|Próximo endereço de parágrafo disponíveis (16 bytes por parágrafo).|  
|**PAGE**|Próximo endereço de páginas disponível (256 bytes por página).|  
|**ALIGN**(*n*)|Avançar disponível *n*endereço do número especificado de bytes. Consulte a seção comentários para obter mais informações.|  
  
 Se esse parâmetro não for especificado, **PARA** é usado por padrão.  
  
 *combine*  
 **PÚBLICO**, **pilha**, **comuns**, **memória**, **em * endereço*, **PRIVADA**  
  
 *Use*  
 **USE16**, **USE32**, **FLAT**  
  
 `characteristics`  
 **INFORMAÇÕES**, **ler**, **gravar**, **EXECUTE**, **compartilhado**, **NOPAGE**, **NOCACHE**, e **descartar**  
  
 Eles têm suporte apenas para COFF e correspondem às características de seção COFF de nome semelhante (por exemplo, **compartilhado** corresponde à IMAGE_SCN_MEM_SHARED). LEITURA define o sinalizador IMAGE_SCN_MEM_READ. O sinalizador somente leitura obsoleto causou a seção limpar o sinalizador IMG_SCN_MEM_WRITE. Se houver `characteristics` estão configurados, as características de padrão não são usadas e apenas os sinalizadores especificados pelo programador estão em vigor.  
  
 `ALIAS(``string``)`  
 Essa cadeia de caracteres é usada como o nome da seção no objeto COFF emitido.  Cria várias seções com o mesmo nome externo, com nomes distintos de segmento (MASM).  
  
 Não há suportada com **/omf**.  
  
 `class`  
 Designa como segmentos devem ser combinados e ordenados no arquivo montado. Os valores típicos são, `'DATA'`, `'CODE'`, `'CONST'` e `'STACK'`  
  
## <a name="remarks"></a>Comentários  
 Para `ALIGN(n)`, `n` pode ser qualquer potência de 2 de 1 para 8192; não tem suporte com **/omf**.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)