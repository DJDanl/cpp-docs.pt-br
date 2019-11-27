---
title: SEGMENT
ms.date: 08/30/2018
f1_keywords:
- SEGMENT
helpviewer_keywords:
- SEGMENT directive
ms.assetid: e6f68367-6714-4f06-a79c-edfa88014430
ms.openlocfilehash: b7344d9cb685e0212748d7835e19f398f14979e7
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74393723"
---
# <a name="segment"></a>SEGMENT

Define um segmento de programa chamado *nome* com atributos de segmento

## <a name="syntax"></a>Sintaxe

> *nome* **segmento** ⟦**ReadOnly**⟧ ⟦*align*⟧ ⟦*Combine*⟧ ⟦*use*⟧ ⟦*características*⟧ **alias (** _String_ **)** ⟦ __'__ *Class* __'__ ⟧ \
> *instruções*\
> *nome* **termina**

#### <a name="parameters"></a>Parâmetros

*align*<br/>
O intervalo de endereços de memória do qual um endereço inicial para o segmento pode ser selecionado. O tipo de alinhamento pode ser qualquer um dos seguintes:

|Tipo de alinhamento|Endereço inicial|
|----------------|----------------------|
|**BYTE**|Próximo endereço de byte disponível.|
|**WORD**|Próximo endereço de palavra disponível (2 bytes por palavra).|
|**DWORD**|Próximo endereço de palavra dupla disponível (4 bytes por palavra dupla).|
|**PARA**|Próximo endereço de parágrafo disponível (16 bytes por parágrafo).|
|**PAGE**|Próximo endereço de página disponível (256 bytes por página).|
|**Alinhar**(*n*)|Próximo endereço do *n*º de bytes disponível. Consulte a seção comentários para obter mais informações.|

Se esse parâmetro não for especificado, o **para** será usado por padrão.

*combinar*\
**Público**, **pilha**, **comum**, **memória**, **em**<em>endereço</em>, **privado**

*usar*\
**USE16**, **USE32**, **simples**

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

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
