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
ms.openlocfilehash: 4d9d0b403e572d6fdea65355702467c89587cc3a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219073"
---
# <a name="cstrbuft-class"></a>Classe CStrBufT

Essa classe fornece a limpeza automática de recursos para `GetBuffer` `ReleaseBuffer` chamadas e em um `CStringT` objeto existente.

## <a name="syntax"></a>Sintaxe

```
template<typename TCharType>
class CStrBufT
```

#### <a name="parameters"></a>parâmetros

*TCharType*<br/>
O tipo de caractere da `CStrBufT` classe. Um dos seguintes pode ser feito:

- **`char`**(para cadeias de caracteres ANSI)

- **`wchar_t`**(para cadeias de caracteres Unicode)

- TCHAR (para cadeias de caracteres ANSI e Unicode)

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|PCXSTR|Um ponteiro para uma cadeia de caracteres constante.|
|PXSTR|Um ponteiro para uma cadeia de caracteres.|
|`StringType`|O tipo de cadeia de caracteres cujo buffer deve ser manipulado por especializações desse modelo de classe.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT::CStrBufT](#cstrbuft)|O construtor para o objeto de buffer de cadeia de caracteres.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT:: SetLength](#setlength)|Define o comprimento do buffer de caracteres do objeto de cadeia de caracteres associado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CStrBufT:: Operator PCXSTR](#operator_pcxstr)|Recupera um **`const`** ponteiro para o buffer de caracteres do objeto de cadeia de caracteres associado.|
|[Operador CStrBufT:: Operator PXSTR](#operator_pxstr)|Recupera um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres associado.|

### <a name="public-constants"></a>Constantes públicas

|Nome|Descrição|
|----------|-----------------|
|[CStrBufT:: AUTO_LENGTH](#auto_length)|Determine automaticamente o novo comprimento da cadeia de caracteres na versão.|
|[CStrBufT:: SET_LENGTH](#set_length)|Definir o comprimento do objeto de cadeia de caracteres em GetBuffer hora|

## <a name="remarks"></a>Comentários

Essa classe é usada como uma classe wrapper para substituir chamadas para [GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [ReleaseBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer), ou [GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) e `ReleaseBuffer` .

Projetado principalmente como uma classe auxiliar, `CStrBufT` fornece uma maneira conveniente para um desenvolvedor trabalhar com o buffer de caracteres de um objeto de cadeia de caracteres sem se preocupar com como ou quando chamar `ReleaseBuffer` . Isso é possível porque o objeto wrapper sai do escopo naturalmente no caso de uma exceção ou vários caminhos de código de saída; fazendo com que seu destruidor libere o recurso de cadeia de caracteres.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr. h

## <a name="cstrbuftauto_length"></a><a name="auto_length"></a>CStrBufT:: AUTO_LENGTH

Determine automaticamente o novo comprimento da cadeia de caracteres na versão.

```
static const DWORD AUTO_LENGTH = 0x01;
```

### <a name="remarks"></a>Comentários

Determine automaticamente o novo comprimento da cadeia de caracteres na versão. A cadeia de caracteres deve ser terminada em nulo.

## <a name="cstrbuftcstrbuft"></a><a name="cstrbuft"></a>CStrBufT::CStrBufT

Constrói um objeto buffer.

```
CStrBufT(StringType& str, int nMinLength, DWORD dwFlags = AUTO_LENGTH) throw(...);
explicit CStrBufT(StringType& str) throw(...);
```

### <a name="parameters"></a>parâmetros

*str*<br/>
O objeto de cadeia de caracteres associado ao buffer. Normalmente, o desenvolvedor usará os TYPEDEFs predefinidos de `CStrBuf` (variante TCHAR), `CStrBufA` ( **`char`** variante) e `CStrBufW` ( **`wchar_t`** variante).

*nMinLength*<br/>
O comprimento mínimo do buffer de caracteres.

*dwFlags*<br/>
Determina se o comprimento da cadeia de caracteres é determinado automaticamente. Um dos seguintes pode ser feito:

- AUTO_LENGTH comprimento da cadeia de caracteres é determinado automaticamente quando [CSimpleStringT:: Release](../../atl-mfc-shared/reference/csimplestringt-class.md#releasebuffer) é chamado. A cadeia de caracteres deve ser terminada em nulo. Valor padrão.

- SET_LENGTH tamanho da cadeia de caracteres é definido quando [CSimpleStringT:: GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) é chamado.

### <a name="remarks"></a>Comentários

Cria um buffer de cadeia de caracteres para o objeto de cadeia de caracteres associado. Durante a construção, [CSimpleStringT:: GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) ou [CSimpleStringT:: GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) é chamado.

Observe que o construtor de cópia é **`private`** .

## <a name="cstrbuftoperator-pcxstr"></a><a name="operator_pcxstr"></a>Operador CStrBufT:: Operator PCXSTR

Acessa diretamente os caracteres armazenados no objeto de cadeia de caracteres associado como uma cadeia de estilo C.

```
operator PCXSTR() const throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caractere para os dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame essa função para retornar um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres. O conteúdo do objeto de cadeia de caracteres não pode ser alterado com este ponteiro.

## <a name="cstrbuftoperator-pxstr"></a><a name="operator_pxstr"></a>Operador CStrBufT:: Operator PXSTR

Acessa diretamente os caracteres armazenados no objeto de cadeia de caracteres associado como uma cadeia de estilo C.

```
operator PXSTR() throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro de caractere para os dados da cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame essa função para retornar um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres. O desenvolvedor pode alterar o conteúdo do objeto de cadeia de caracteres com esse ponteiro.

## <a name="cstrbuftpcxstr"></a><a name="pcxstr"></a>CStrBufT::P CXSTR

Um ponteiro para uma cadeia de caracteres constante.

```
typedef CSimpleStringT<TCharType>::PCXSTR PCXSTR;
```

## <a name="cstrbuftpxstr"></a><a name="pxstr"></a>CStrBufT::P XSTR

Um ponteiro para uma cadeia de caracteres.

```
typedef CSimpleStringT<TCharType>::PXSTR PXSTR;
```

## <a name="cstrbuftset_length"></a><a name="set_length"></a>CStrBufT:: SET_LENGTH

Defina o comprimento do objeto de cadeia de caracteres no `GetBuffer` momento.

```
static const DWORD SET_LENGTH = 0x02;
```

### <a name="remarks"></a>Comentários

Defina o comprimento do objeto de cadeia de caracteres em GetBuffer hora.

Determina se [CSimpleStringT:: GetBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffer) e [CSimpleStringT:: GetBufferSetLength](../../atl-mfc-shared/reference/csimplestringt-class.md#getbuffersetlength) são chamados quando o objeto de buffer de cadeia de caracteres é construído.

## <a name="cstrbuftsetlength"></a><a name="setlength"></a>CStrBufT:: SetLength

Define o comprimento do buffer de caracteres.

```cpp
void SetLength(int nLength);
```

### <a name="parameters"></a>parâmetros

*nLength*<br/>
O novo comprimento do buffer de caracteres do objeto de cadeia de caracteres.

> [!NOTE]
> Deve ser menor ou igual ao tamanho mínimo do buffer especificado no construtor de `CStrBufT` .

### <a name="remarks"></a>Comentários

Chame essa função para definir o comprimento da cadeia de caracteres representada pelo objeto de buffer.

## <a name="cstrbuftstringtype"></a><a name="stringtype"></a>CStrBufT:: StringType

O tipo de cadeia de caracteres cujo buffer deve ser manipulado por especializações desse modelo de classe.

```
typedef CSimpleStringT<TCharType> StringType;
```

### <a name="remarks"></a>Comentários

`TCharType`é o tipo de caractere usado para especializar o modelo de classe.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
