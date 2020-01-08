---
title: SEGMENT
ms.date: 12/16/2019
f1_keywords:
- SEGMENT
helpviewer_keywords:
- SEGMENT directive
ms.assetid: e6f68367-6714-4f06-a79c-edfa88014430
ms.openlocfilehash: 569604bfd6ed11039ce5492223b8d5f986ceea7a
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318456"
---
# <a name="segment"></a>SEGMENT

Define um segmento de programa chamado *nome* com atributos de segmento

## <a name="syntax"></a>Sintaxe

> *nome* **segmento** ⟦**ReadOnly**⟧ ⟦*align*⟧ ⟦*Combine*⟧ ⟦*use*⟧ ⟦*características*⟧ **alias (** _String_ **)** ⟦ __'__ *Class* __'__ ⟧ \
> *instruções*\
> *nome* **termina**

#### <a name="parameters"></a>Parâmetros

*alinhar*\
O intervalo de endereços de memória do qual um endereço inicial para o segmento pode ser selecionado. O tipo de alinhamento pode ser qualquer um dos seguintes:

|Tipo de alinhamento|Endereço inicial|
|----------------|----------------------|
|**BYTE**|Próximo endereço de byte disponível.|
|**WORD**|Próximo endereço de palavra disponível (2 bytes por palavra).|
|**DWORD**|Próximo endereço de palavra dupla disponível (4 bytes por palavra dupla).|
|**PARA**|Próximo endereço de parágrafo disponível (16 bytes por parágrafo).|
|**PAGE**|Próximo endereço de página disponível (256 bytes por página).|
|**ALIGN**(*n*)|Próximo endereço do *n*º de bytes disponível. Consulte a seção comentários para obter mais informações.|

Se esse parâmetro não for especificado, o **para** será usado por padrão.

*combinar* (somente MASM de 32 bits) \
**Público**, **pilha**, **comum**, **memória**, **em**<em>endereço</em>, **privado**

*uso* (somente MASM de 32 bits) \
**USE16**, **USE32**, **FLAT**

*características*\
**Informações**, **leitura**, **gravação**, **execução**, **compartilhada**, **noPage**, **NoCache**e **descarte**

Eles têm suporte apenas para COFF e correspondem às características da seção COFF de nome semelhante (por exemplo, **compartilhado** corresponde a IMAGE_SCN_MEM_SHARED). LER define o sinalizador de IMAGE_SCN_MEM_READ. O sinalizador somente leitura obsoleto fez com que a seção limpasse o sinalizador IMG_SCN_MEM_WRITE. Se alguma das *características* for definida, as características padrão não serão usadas e somente os sinalizadores especificados pelo programador estarão em vigor.

_string_\
Essa cadeia de caracteres é usada como o nome da seção no objeto COFF emitido.  Cria várias seções com o mesmo nome externo, com nomes de segmento MASM distintos.

Sem suporte com **/OMF**.

*class*\
Designa como os segmentos devem ser combinados e ordenados no arquivo montado. Os valores típicos são, `'DATA'`, `'CODE'`, `'CONST'` e `'STACK'`

## <a name="remarks"></a>Comentários

Por `ALIGN(n)`, *n* pode ser qualquer potência de 2 de 1 a 8192; sem suporte com **/OMF**.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
