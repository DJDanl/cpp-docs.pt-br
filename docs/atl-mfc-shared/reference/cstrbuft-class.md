---
title: Classe CStrBufT
ms.date: 10/18/2018
f1_keywords:
- CStrBufT
- ATLSIMPSTR/ATL::CStrBufT
- ATLSIMPSTR/ATL::CStrBufT::CStrBufT
- ATLSIMPSTR/ATL::CStrBufT::SetLength
- ATLSIMPSTR/ATL::CStrBufT::AUTO_LENGTH
- ATLSIMPSTR/ATL::CStrBufT::SET_LENGTH
helpviewer_keywords:
- strings [C++], custom memory management
- CStrBufT class
- shared classes, CStrBufT
ms.assetid: 6b50fa8f-87e8-4ed4-a229-157ce128710f
ms.openlocfilehash: 84c67aa8ea819f420368a72a2374f800f3d89055
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317639"
---
# <a name="cstrbuft-class"></a>Classe CStrBufT

Esta classe fornece limpeza `GetBuffer` automática `ReleaseBuffer` de recursos `CStringT` e solicita um objeto existente.

## <a name="syntax"></a>Sintaxe

```
template<typename TCharType>
class CStrBufT
```

#### <a name="parameters"></a>Parâmetros

*TcharType*<br/>
O tipo de `CStrBufT` personagem da classe. Um dos seguintes pode ser feito:

- **char** (para strings de caracteres ANSI)

- **wchar_t** (para strings de caracteres Unicode)

- TCHAR (para seqüências de caracteres ANSI e Unicode)

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|Pcxstr|Um ponteiro para uma seqüência constante.|
|PXSTR|Um ponteiro para uma corda.|
|`StringType`|O tipo de string cujo buffer deve ser manipulado por especializações deste modelo de classe.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::CstrBufT](#cstrbuft)|O construtor para o objeto tampão de seqüência de strings.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::SetLength](#setlength)|Define o comprimento do buffer de caracteres do objeto de seqüência de caracteres associado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT:operador PCXSTR](#operator_pcxstr)|Recupera um **ponteiro const** para o buffer de caracteres do objeto de seqüência associado.|
|[CStrBufT::operador PXSTR](#operator_pxstr)|Recupera um ponteiro para o buffer de caracteres do objeto de seqüência associado.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[CstrBufT::AUTO_LENGTH](#auto_length)|Determine automaticamente o novo comprimento da seqüência na liberação.|
|[CStrBufT::SET_LENGTH](#set_length)|Defina o comprimento do objeto de seqüência no tempo GetBuffer|

## <a name="remarks"></a>Comentários

Esta classe é usada como uma classe de invólucro para substituir chamadas `ReleaseBuffer`para [GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [ReleaseBuffer,](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer)ou [GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) e .

Projetado principalmente como uma classe `CStrBufT` auxiliar, fornece uma maneira conveniente para um desenvolvedor trabalhar com o buffer `ReleaseBuffer`de caracteres de um objeto de seqüência sem se preocupar sobre como ou quando chamar . Isso é possível porque o objeto de invólucro sai do escopo naturalmente no caso de uma exceção ou vários caminhos de código de saída; fazendo com que seu destruidor liberte o recurso de string.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

## <a name="cstrbuftauto_length"></a><a name="auto_length"></a>CstrBufT::AUTO_LENGTH

Determine automaticamente o novo comprimento da seqüência na liberação.

```
static const DWORD AUTO_LENGTH = 0x01;
```

### <a name="remarks"></a>Comentários

Determine automaticamente o novo comprimento da seqüência na liberação. A seqüência deve ser nula.

## <a name="cstrbuftcstrbuft"></a><a name="cstrbuft"></a>CStrBufT::CstrBufT

Constrói um objeto tampão.

```
CStrBufT(StringType& str, int nMinLength, DWORD dwFlags = AUTO_LENGTH) throw(...);
explicit CStrBufT(StringType& str) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Str*<br/>
O objeto de seqüência associado ao buffer. Normalmente, o desenvolvedor usará os typedefs predefinidos `CStrBuf` da (variante TCHAR), `CStrBufA` (variante**char)** e `CStrBufW` **(wchar_t** variante).

*nMinLength*<br/>
O comprimento mínimo do buffer de caracteres.

*dwFlags*<br/>
Determina se o comprimento da corda é automaticamente determinado. Um dos seguintes pode ser feito:

- AUTO_LENGTH comprimento da corda é automaticamente determinado quando [CSimpleStringT::Liberação](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) é chamada. A seqüência deve ser nula. Valor padrão.

- SET_LENGTH comprimento da seqüência de strings é definido quando [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) é chamado.

### <a name="remarks"></a>Comentários

Cria um buffer de string para o objeto de seqüência associado. Durante a construção, [CSimpleStringT::GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) ou [CSimpleStringT::GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) é chamado.

Observe que o construtor de cópias é **privado**.

## <a name="cstrbuftoperator-pcxstr"></a><a name="operator_pcxstr"></a>CStrBufT:operador PCXSTR

Acessa diretamente caracteres armazenados no objeto de seqüência associado como uma seqüência de caracteres estilo C.

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caracteres para os dados da seqüência.

### <a name="remarks"></a>Comentários

Chame esta função para retornar um ponteiro para o buffer de caracteres de um objeto de seqüência. O conteúdo do objeto de seqüência não pode ser alterado com este ponteiro.

## <a name="cstrbuftoperator-pxstr"></a><a name="operator_pxstr"></a>CStrBufT::operador PXSTR

Acessa diretamente caracteres armazenados no objeto de seqüência associado como uma seqüência de caracteres estilo C.

```
operator PXSTR() throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caracteres para os dados da seqüência.

### <a name="remarks"></a>Comentários

Chame esta função para retornar um ponteiro para o buffer de caracteres de um objeto de seqüência. O desenvolvedor pode alterar o conteúdo do objeto de seqüência com este ponteiro.

## <a name="cstrbuftpcxstr"></a><a name="pcxstr"></a>CStrBufT::PCXSTR

Um ponteiro para uma seqüência constante.

```
typedef CSimpleStringT<TCharType>::PCXSTR PCXSTR;
```

## <a name="cstrbuftpxstr"></a><a name="pxstr"></a>CStrBufT::PXSTR

Um ponteiro para uma corda.

```
typedef CSimpleStringT<TCharType>::PXSTR PXSTR;
```

## <a name="cstrbuftset_length"></a><a name="set_length"></a>CStrBufT::SET_LENGTH

Defina o comprimento do `GetBuffer` objeto de corda no momento.

```
static const DWORD SET_LENGTH = 0x02;
```

### <a name="remarks"></a>Comentários

Defina o comprimento do objeto de seqüência no tempo GetBuffer.

Determina se [CSimpleStringT:GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT::GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) são chamados quando o objeto buffer de seqüência é construído.

## <a name="cstrbuftsetlength"></a><a name="setlength"></a>CStrBufT::SetLength

Define o comprimento do buffer de caracteres.

```
void SetLength(int nLength);
```

### <a name="parameters"></a>Parâmetros

*Nlength*<br/>
O novo comprimento do buffer de caracteres do objeto de seqüência.

> [!NOTE]
> Deve ser menor ou igual ao comprimento mínimo de `CStrBufT`tampão especificado na construtora de .

### <a name="remarks"></a>Comentários

Chame esta função para definir o comprimento da seqüência representada pelo objeto tampão.

## <a name="cstrbuftstringtype"></a><a name="stringtype"></a>CStrBufT::StringType

O tipo de string cujo buffer deve ser manipulado por especializações deste modelo de classe.

```
typedef CSimpleStringT<TCharType> StringType;
```

### <a name="remarks"></a>Comentários

`TCharType`é o tipo de caractere usado para especializar o modelo de classe.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
