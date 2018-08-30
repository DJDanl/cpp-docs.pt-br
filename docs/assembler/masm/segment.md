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
ms.openlocfilehash: f5defce11b611f23b67e5e44ac1b9d406f73c0ae
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210413"
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
 O intervalo de endereços de memória do qual um endereço inicial para o segmento pode ser selecionado. O tipo de alinhamento pode ser qualquer uma das seguintes opções:  
  
|Alinhar tipo|Endereço inicial|  
|----------------|----------------------|  
|**BYTE**|Próximo endereço de bytes disponíveis.|  
|**WORD**|Próximo endereço disponível do word (2 bytes por palavra).|  
|**DWORD**|Próximo endereço disponível palavra de dupla (4 bytes por palavra dupla).|  
|**PARA**|Endereço do próximo parágrafo disponíveis (16 bytes por parágrafo).|  
|**PAGE**|Endereço de próxima página disponível (256 bytes por página).|  
|**ALIGN**(*n*)|Próxima disponível *n*endereço de byte th. Consulte a seção Observações para obter mais informações.|  
  
 Se esse parâmetro não for especificado, **PARA** é usado por padrão.  
  
 *combine*  
 **PÚBLICO**, **pilha**, **comuns**, **memória**, **em**<em>endereço</em>, **Particular**  
  
 *Use*  
 **USE16**, **USE32**, **FLAT**  
  
 `characteristics`  
 **INFO**, **leia**, **ESCREVER**, **EXECUTE**, **compartilhado**, **NOPAGE**, **NOCACHE**, e **descartar**  
  
 Esses são suportados apenas para COFF e correspondem às características de seção COFF de nome semelhante (por exemplo, **compartilhado** corresponde à IMAGE_SCN_MEM_SHARED). LEITURA define o sinalizador IMAGE_SCN_MEM_READ. O sinalizador somente leitura obsoleto causado a seção para limpar o sinalizador IMG_SCN_MEM_WRITE. Se houver `characteristics` forem definidos, as características padrão não são usadas e somente os sinalizadores especificados pelo programador estão em vigor.  
  
 `ALIAS(``string``)`  
 Essa cadeia de caracteres é usada como o nome da seção no objeto COFF emitido.  Cria várias seções com o mesmo nome externo, com nomes distintos de segmentos (MASM).  
  
 Não há suportada com **/omf**.  
  
 `class`  
 Designa como segmentos devem ser combinados e ordenados no arquivo montado. Os valores típicos são, `'DATA'`, `'CODE'`, `'CONST'` e `'STACK'`  
  
## <a name="remarks"></a>Comentários  
 Para `ALIGN(n)`, `n` pode ser qualquer potência de 2 de 1 a 8192; não tem suporte com **/omf**.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)