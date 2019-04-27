---
title: Funções de Retorno de Chamada Usadas pelo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.functions
helpviewer_keywords:
- callback functions [MFC], MFC
- MFC, callback functions
- functions [MFC], callback
- callback functions [MFC]
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
ms.openlocfilehash: e3440530dfe30b6667012c76b2904dbb2786c199
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62152133"
---
# <a name="callback-functions-used-by-mfc"></a>Funções de Retorno de Chamada Usadas pelo MFC

Três funções de retorno de chamada aparecem na biblioteca de classes Microsoft Foundation. Essas funções de retorno de chamada são passadas para [CDC:: enumobjects](../../mfc/reference/cdc-class.md#enumobjects), [CDC:: graystring](../../mfc/reference/cdc-class.md#graystring), e [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc). Observe que todas as funções de retorno de chamada devem interceptar exceções de MFC antes de retornar ao Windows, já que as exceções não podem ser geradas entre limites de retorno de chamada. Para obter mais informações sobre exceções, consulte o artigo [exceções](../../mfc/exception-handling-in-mfc.md).

|Nome||
|----------|-----------------|
|[Função de retorno de chamada para CDC::EnumObjects](#enum_objects)||
|[Função de retorno de chamada para CDC::GrayString](#graystring)||
|[Função de retorno de chamada para CDC::SetAbortProc](#setabortproc)||

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="enum_objects"></a> Função de retorno de chamada para CDC:: enumobjects

O *ObjectFunc* nome é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
int CALLBACK EXPORT ObjectFunc(
    LPSTR lpszLogObject,
    LPSTR* lpData);
```

### <a name="parameters"></a>Parâmetros

*lpszLogObject*<br/>
Aponta para um [LOGPEN](/windows/desktop/api/Wingdi/ns-wingdi-taglogpen) ou [LOGBRUSH](/windows/desktop/api/wingdi/ns-wingdi-taglogbrush) estrutura de dados que contém informações sobre os atributos a lógicas do objeto.

*lpData*<br/>
Pontos de dados fornecida pelo aplicativo passado para o `EnumObjects` função.

### <a name="return-value"></a>Valor de retorno

A função de retorno de chamada retorna um **int**. O valor deste retorno é definido pelo usuário. Se a função de retorno de chamada retornar 0, `EnumObjects` para no início de enumeração.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado.

## <a name="graystring"></a>  Função de retorno de chamada para CDC:: graystring

*OutputFunc* é um espaço reservado para o nome da função de retorno de chamada fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT OutputFunc(
    HDC hDC,
    LPARAM lpData,
    int nCount);
```

### <a name="parameters"></a>Parâmetros

*hDC*<br/>
Identifica um contexto de dispositivo de memória com um bitmap pelo menos a largura e altura especificada por `nWidth` e `nHeight` para `GrayString`.

*lpData*<br/>
Aponta para a cadeia de caracteres a ser desenhada.

*nCount*<br/>
Especifica o número de caracteres de saída.

### <a name="return-value"></a>Valor de retorno

O valor de retorno da função de retorno de chamada deve ser verdadeiro para indicar êxito; Caso contrário, ele será FALSE.

### <a name="remarks"></a>Comentários

A função de retorno de chamada (*OutputFunc*) deve desenhar uma imagem em relação as coordenadas (0,0) em vez de (*x*, *y*).

## <a name="setabortproc"></a>  Função de retorno de chamada para CDC:: SetAbortProc

O nome *AbortFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT AbortFunc(
    HDC hPr,
    int code);
```

### <a name="parameters"></a>Parâmetros

*hPr*<br/>
Identifica o contexto de dispositivo.

*code*<br/>
Especifica se ocorreu um erro. É 0 se nenhum erro tiver ocorrido. É SP_OUTOFDISK se o Gerenciador de impressão está sem espaço em disco e serão disponibilizados mais espaço em disco se o aplicativo espera. Se *código* é SP_OUTOFDISK, o aplicativo não precisa cancelar o trabalho de impressão. Se não existir, ela deverá produzir para o Gerenciador de impressão chamando o `PeekMessage` ou `GetMessage` função do Windows.

### <a name="return-value"></a>Valor de retorno

O valor de retorno da função de manipulador de anulação é diferente de zero se o trabalho de impressão é continuar e 0 se ele for cancelado.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado, conforme descrito na seção de comentários [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc).

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md)<br/>
[CDC::EnumObjects](../../mfc/reference/cdc-class.md#enumobjects)<br/>
[CDC::SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc)<br/>
[CDC::GrayString](../../mfc/reference/cdc-class.md#graystring)
