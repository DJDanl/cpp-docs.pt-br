---
title: Funções de Retorno de Chamada Usadas pelo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- callback functions [MFC], MFC
- MFC, callback functions
- functions [MFC], callback
- callback functions [MFC]
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
ms.openlocfilehash: 19c0bd3a0685abe36c020a5dda930f5683a4baa9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87183429"
---
# <a name="callback-functions-used-by-mfc"></a>Funções de Retorno de Chamada Usadas pelo MFC

Três funções de retorno de chamada aparecem na biblioteca MFC. Essas funções de retorno de chamada são passadas para [CDC:: EnumObjects](../../mfc/reference/cdc-class.md#enumobjects), [CDC:: GrayString](../../mfc/reference/cdc-class.md#graystring)e [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc). Observe que todas as funções de retorno de chamada devem interceptar exceções do MFC antes de retornar ao Windows, já que as exceções não podem ser lançadas em limites de retorno Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

|Nome||
|----------|-----------------|
|[Função de retorno de chamada para CDC::EnumObjects](#enum_objects)||
|[Função de retorno de chamada para CDC::GrayString](#graystring)||
|[Função de retorno de chamada para CDC::SetAbortProc](#setabortproc)||

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="callback-function-for-cdcenumobjects"></a><a name="enum_objects"></a>Função de retorno de chamada para CDC:: EnumObjects

O nome do *ObjectFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
int CALLBACK EXPORT ObjectFunc(
    LPSTR lpszLogObject,
    LPSTR* lpData);
```

### <a name="parameters"></a>parâmetros

*lpszLogObject*<br/>
Aponta para uma estrutura de dados [LOGPEN](/windows/win32/api/Wingdi/ns-wingdi-logpen) ou [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre os atributos lógicos do objeto.

*lpData*<br/>
Aponta para os dados fornecidos pelo aplicativo passados para a `EnumObjects` função.

### <a name="return-value"></a>Valor retornado

A função de retorno de chamada retorna um **`int`** . O valor desse retorno é definido pelo usuário. Se a função de retorno de chamada retornar 0, `EnumObjects` interromperá a enumeração antecipadamente.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado.

## <a name="callback-function-for-cdcgraystring"></a><a name="graystring"></a>Função de retorno de chamada para CDC:: GrayString

*OutputFunc* é um espaço reservado para o nome da função de retorno de chamada fornecido pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT OutputFunc(
    HDC hDC,
    LPARAM lpData,
    int nCount);
```

### <a name="parameters"></a>parâmetros

*hDC*<br/>
Identifica um contexto de dispositivo de memória com um bitmap de pelo menos a largura e a altura especificadas por `nWidth` e `nHeight` para `GrayString` .

*lpData*<br/>
Aponta para a cadeia de caracteres a ser desenhada.

*nCount*<br/>
Especifica o número de caracteres a serem gerados.

### <a name="return-value"></a>Valor retornado

O valor de retorno da função de retorno de chamada deve ser verdadeiro para indicar êxito; caso contrário, será FALSE.

### <a name="remarks"></a>Comentários

A função de retorno de chamada (*OutputFunc*) deve desenhar uma imagem em relação às coordenadas (0, 0) em vez de (*x*, *y*).

## <a name="callback-function-for-cdcsetabortproc"></a><a name="setabortproc"></a>Função de retorno de chamada para CDC:: SetAbortProc

O nome *AbortFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT AbortFunc(
    HDC hPr,
    int code);
```

### <a name="parameters"></a>parâmetros

*hPr*<br/>
Identifica o contexto do dispositivo.

*code*<br/>
Especifica se ocorreu um erro. Será 0 se nenhum erro tiver ocorrido. É SP_OUTOFDISK se o Gerenciador de impressão estiver sem espaço em disco no momento e mais espaço em disco ficará disponível se o aplicativo aguardar. Se o *código* for SP_OUTOFDISK, o aplicativo não precisará abortar o trabalho de impressão. Caso contrário, ele deve produzir o Gerenciador de impressão chamando a `PeekMessage` função ou do `GetMessage` Windows.

### <a name="return-value"></a>Valor retornado

O valor de retorno da função de identificador de anulação será diferente de zero se o trabalho de impressão for para continuar e 0 se for cancelado.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado conforme descrito na seção comentários de [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc).

## <a name="see-also"></a>Confira também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md)<br/>
[CDC:: EnumObjects](../../mfc/reference/cdc-class.md#enumobjects)<br/>
[CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc)<br/>
[CDC:: Cinzastring](../../mfc/reference/cdc-class.md#graystring)
