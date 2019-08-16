---
title: Funções de Retorno de Chamada Usadas pelo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- callback functions [MFC], MFC
- MFC, callback functions
- functions [MFC], callback
- callback functions [MFC]
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
ms.openlocfilehash: 9e51774b2158a81fce05dc0bd27e296e4ad94faa
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507708"
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

## <a name="enum_objects"></a>Função de retorno de chamada para CDC:: EnumObjects

O nome do ObjectFunc é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
int CALLBACK EXPORT ObjectFunc(
    LPSTR lpszLogObject,
    LPSTR* lpData);
```

### <a name="parameters"></a>Parâmetros

*lpszLogObject*<br/>
Aponta para uma estrutura de dados [LOGPEN](/windows/win32/api/Wingdi/ns-wingdi-logpen) ou [LOGBRUSH](/windows/win32/api/wingdi/ns-wingdi-logbrush) que contém informações sobre os atributos lógicos do objeto.

*lpData*<br/>
Aponta para os dados fornecidos pelo aplicativo passados para a `EnumObjects` função.

### <a name="return-value"></a>Valor de retorno

A função de retorno de chamada retorna um **int**. O valor desse retorno é definido pelo usuário. Se a função de retorno de chamada `EnumObjects` retornar 0, interromperá a enumeração antecipadamente.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado.

## <a name="graystring"></a>Função de retorno de chamada para CDC:: GrayString

*OutputFunc* é um espaço reservado para o nome da função de retorno de chamada fornecido pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT OutputFunc(
    HDC hDC,
    LPARAM lpData,
    int nCount);
```

### <a name="parameters"></a>Parâmetros

*hDC*<br/>
Identifica um contexto de dispositivo de memória com um bitmap de pelo menos a largura e a `nWidth` altura `nHeight` especificadas `GrayString`por e para.

*lpData*<br/>
Aponta para a cadeia de caracteres a ser desenhada.

*nCount*<br/>
Especifica o número de caracteres a serem gerados.

### <a name="return-value"></a>Valor de retorno

O valor de retorno da função de retorno de chamada deve ser verdadeiro para indicar êxito; caso contrário, será FALSE.

### <a name="remarks"></a>Comentários

A função de retorno de chamada (*OutputFunc*) deve desenhar uma imagem em relação às coordenadas (0, 0) em vez de (*x*, *y*).

## <a name="setabortproc"></a>Função de retorno de chamada para CDC:: SetAbortProc

O nome *AbortFunc* é um espaço reservado para o nome da função fornecida pelo aplicativo.

### <a name="syntax"></a>Sintaxe

```
BOOL CALLBACK EXPORT AbortFunc(
    HDC hPr,
    int code);
```

### <a name="parameters"></a>Parâmetros

*hPr*<br/>
Identifica o contexto do dispositivo.

*código*<br/>
Especifica se ocorreu um erro. Será 0 se nenhum erro tiver ocorrido. É SP_OUTOFDISK se o Gerenciador de impressão estiver sem espaço em disco no momento e mais espaço em disco ficará disponível se o aplicativo aguardar. Se o *código* for SP_OUTOFDISK, o aplicativo não precisará abortar o trabalho de impressão. Caso contrário, ele deve produzir o Gerenciador de impressão chamando a função ou `PeekMessage` `GetMessage` do Windows.

### <a name="return-value"></a>Valor de retorno

O valor de retorno da função de identificador de anulação será diferente de zero se o trabalho de impressão for para continuar e 0 se for cancelado.

### <a name="remarks"></a>Comentários

O nome real deve ser exportado conforme descrito na seção comentários de [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc).

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md)<br/>
[CDC:: EnumObjects](../../mfc/reference/cdc-class.md#enumobjects)<br/>
[CDC::SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc)<br/>
[CDC::GrayString](../../mfc/reference/cdc-class.md#graystring)
