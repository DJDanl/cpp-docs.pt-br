---
title: Funções de Retorno de Chamada Usadas pelo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- callback functions [MFC], MFC
- MFC, callback functions
- functions [MFC], callback
- callback functions [MFC]
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
ms.openlocfilehash: 8d84f939795e768c6b1356dcd8dc291421aedfdc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371132"
---
# <a name="callback-functions-used-by-mfc"></a>Funções de Retorno de Chamada Usadas pelo MFC

Três funções de retorno de chamada aparecem na Biblioteca de Classes da Microsoft Foundation. Essas funções de retorno de chamada são passadas para [CDC::EnumObjects,](../../mfc/reference/cdc-class.md#enumobjects) [CDC::GrayString](../../mfc/reference/cdc-class.md#graystring)e [CDC::SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc). Observe que todas as funções de retorno de chamada devem prender as exceções do MFC antes de retornar ao Windows, uma vez que as exceções não podem ser lançadas através dos limites de retorno de chamada. Para obter mais informações sobre exceções, consulte o artigo [Exceções](../../mfc/exception-handling-in-mfc.md).

|Nome||
|----------|-----------------|
|[Função de retorno de chamada para CDC::EnumObjects](#enum_objects)||
|[Função de retorno de chamada para CDC::GrayString](#graystring)||
|[Função de retorno de chamada para CDC::SetAbortProc](#setabortproc)||

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="callback-function-for-cdcenumobjects"></a><a name="enum_objects"></a>Função de retorno de chamada para CDC::EnumObjects

O nome *ObjectFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
int CALLBACK EXPORT ObjectFunc(
    LPSTR lpszLogObject,
    LPSTR* lpData);
```

### <a name="parameters"></a>Parâmetros

*lpszLogObject*<br/>
Aponta para uma estrutura de dados [LOGPEN](/windows/win32/api/Wingdi/ns-wingdi-logpen) ou [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre os atributos lógicos do objeto.

*Lpdata*<br/>
Aponta para os dados fornecidos `EnumObjects` pelo aplicativo passados para a função.

### <a name="return-value"></a>Valor retornado

A função de retorno de chamada retorna um **int**. O valor deste retorno é definido pelo usuário. Se a função de `EnumObjects` retorno de chamada retornar 0, interrompe a enumeração mais cedo.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado.

## <a name="callback-function-for-cdcgraystring"></a><a name="graystring"></a>Função de retorno de chamada para CDC::GrayString

*OutputFunc* é um espaço reservado para o nome da função de retorno de chamada fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT OutputFunc(
    HDC hDC,
    LPARAM lpData,
    int nCount);
```

### <a name="parameters"></a>Parâmetros

*Hdc*<br/>
Identifica um contexto do dispositivo de memória com um bitmap `nWidth` `nHeight` de `GrayString`pelo menos a largura e altura especificadas por e para .

*Lpdata*<br/>
Aponta para a cadeia de caracteres a ser desenhada.

*Ncount*<br/>
Especifica o número de caracteres a serem produzidos.

### <a name="return-value"></a>Valor retornado

O valor de retorno da função de retorno da função de retorno deve ser VERDADEIRO para indicar o sucesso; caso contrário, é FALSO.

### <a name="remarks"></a>Comentários

A função de retorno de chamada *(OutputFunc)* deve desenhar uma imagem relativa às coordenadas (0,0) em vez de *(x*, *y*).

## <a name="callback-function-for-cdcsetabortproc"></a><a name="setabortproc"></a>Função de retorno de chamada para CDC::SetAbortProc

O nome *AbortFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT AbortFunc(
    HDC hPr,
    int code);
```

### <a name="parameters"></a>Parâmetros

*Hpr*<br/>
Identifica o contexto do dispositivo.

*Código*<br/>
Especifica se ocorreu um erro. É 0 se não ocorreu nenhum erro. É SP_OUTOFDISK se o Gerenciador de Impressão estiver atualmente sem espaço em disco e mais espaço em disco estará disponível se o aplicativo esperar. Se *o código* for SP_OUTOFDISK, o aplicativo não precisa abortar o trabalho de impressão. Se isso não acontecer, ele deve ceder `PeekMessage` ao `GetMessage` Gerenciador de impressão chamando a função ou Windows.

### <a name="return-value"></a>Valor retornado

O valor de devolução da função abort-handler não é zero se o trabalho de impressão continuar, e 0 se for cancelado.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado conforme descrito na seção Observações do [CDC::SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc).

## <a name="see-also"></a>Confira também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md)<br/>
[CDC::EnumObjects](../../mfc/reference/cdc-class.md#enumobjects)<br/>
[CDC::SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc)<br/>
[CDC::GrayString](../../mfc/reference/cdc-class.md#graystring)
