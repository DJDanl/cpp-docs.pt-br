---
title: Funções de retorno de chamada usadas pelo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.functions
dev_langs:
- C++
helpviewer_keywords:
- callback functions [MFC], MFC
- MFC, callback functions
- functions [MFC], callback
- callback functions [MFC]
ms.assetid: b2a6857c-fdd3-45ec-8fd8-2e71fac77582
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 96db2ea0c28e14f7a8e614d94e18cd3fad3cda53
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37339004"
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
 *lpszLogObject*  
 Aponta para um [LOGPEN](../../mfc/reference/logpen-structure.md) ou [LOGBRUSH](../../mfc/reference/logbrush-structure.md) estrutura de dados que contém informações sobre os atributos a lógicas do objeto.  
  
 *lpData*  
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
 *hDC*  
 Identifica um contexto de dispositivo de memória com um bitmap pelo menos a largura e altura especificada por `nWidth` e `nHeight` para `GrayString`.  
  
 *lpData*  
 Aponta para a cadeia de caracteres a ser desenhada.  
  
 *nCount*  
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
 *hPr*  
 Identifica o contexto de dispositivo.  
  
 *Código*  
 Especifica se ocorreu um erro. É 0 se nenhum erro tiver ocorrido. É SP_OUTOFDISK se o Gerenciador de impressão está sem espaço em disco e serão disponibilizados mais espaço em disco se o aplicativo espera. Se *código* é SP_OUTOFDISK, o aplicativo não precisa cancelar o trabalho de impressão. Se não existir, ela deverá produzir para o Gerenciador de impressão chamando o `PeekMessage` ou `GetMessage` função do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno da função de manipulador de anulação é diferente de zero se o trabalho de impressão é continuar e 0 se ele for cancelado.  
  
### <a name="remarks"></a>Comentários  
 O nome real deve ser exportado, conforme descrito na seção de comentários [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc).  
 
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md) [CDC:: enumobjects](../../mfc/reference/cdc-class.md#enumobjects) [CDC:: SetAbortProc](../../mfc/reference/cdc-class.md#setabortproc) [CDC:: graystring](../../mfc/reference/cdc-class.md#graystring)

