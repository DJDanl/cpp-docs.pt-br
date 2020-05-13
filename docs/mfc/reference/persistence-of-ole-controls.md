---
title: Persistência de controles OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE controls [MFC], persistence
- persistence, OLE controls
ms.assetid: 64f8dc80-f110-41af-b3ea-14948f6bfdf7
ms.openlocfilehash: 88707da503b1d1cdc809827dc4d1bac0ccad9b5b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373005"
---
# <a name="persistence-of-ole-controls"></a>Persistência de controles OLE

Uma das capacidades dos controles OLE é a persistência da propriedade (ou serialização), que permite que o controle OLE leia ou escreva valores de propriedade de e para um arquivo ou fluxo. Um aplicativo de contêiner pode usar serialização para armazenar os valores de propriedade de um controle mesmo depois que o aplicativo tiver destruído o controle. Os valores de propriedade do controle OLE podem então ser lidos a partir do arquivo ou do fluxo quando uma nova instância do controle é criada posteriormente.

### <a name="persistence-of-ole-controls"></a>Persistência de controles OLE

|||
|-|-|
|[PX_Blob](#px_blob)|Troca uma propriedade de controle que armazena dados binários de objetogrande (BLOB).|
|[PX_Bool](#px_bool)|Troca uma propriedade de controle do tipo **BOOL**.|
|[PX_Color](#px_color)|Troca uma propriedade colorida de um controle.|
|[PX_Currency](#px_currency)|Troca uma propriedade de controle do tipo **CY**.|
|[PX_DataPath](#px_datapath)|Troca uma propriedade `CDataPathProperty`de controle do tipo .|
|[PX_Double](#px_double)|Troca uma propriedade de controle do tipo **duplo**.|
|[PX_Font](#px_font)|Troca uma propriedade de fonte de um controle.|
|[PX_Float](#px_float)|Troca uma propriedade de controle do tipo **float**.|
|[PX_IUnknown](#px_iunknown)|Troca uma propriedade de controle de tipo indefinido.|
|[PX_Long](#px_long)|Troca uma propriedade de controle de tipo **longo**.|
|[PX_Picture](#px_picture)|Troca uma propriedade de um controle.|
|[PX_Short](#px_short)|Troca uma propriedade de controle do tipo **curto**.|
|[PX_ULong](#px_ulong)|Troca uma propriedade de controle do tipo **ULONG**.|
|[PX_UShort](#px_ushort)|Troca uma propriedade de controle do tipo **USHORT**.|
|[PXstring](#px_string)|Troca uma propriedade de controle de seqüência de caracteres.|
|[PX_VBXFontConvert](#px_vbxfontconvert)|Troca as propriedades relacionadas à fonte de um controle VBX em uma propriedade de fonte de controle OLE.|

Além disso, `AfxOleTypeMatchGuid` a função global é fornecida para testar uma correspondência entre um TYPEDESC e um dado GUID.

## <a name="px_blob"></a><a name="px_blob"></a>PX_Blob

Chame essa função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade que armazena dados binários de objeto grande (BLOB).

```cpp
BOOL PX_Blob(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    HGLOBAL& hBlob,
    HGLOBAL hBlobDefault = NULL);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Hblob*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*Hblobdefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou escrito para a variável referenciada por *hBlob,* conforme apropriado. Esta variável deve ser inicializada `PX_Blob` para NULL antes de inicialmente chamar pela primeira vez (normalmente, isso pode ser feito no construtor do controle). Se *hBlobDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer motivo, o processo de inicialização ou serialização do controle falhar.

As alças *hBlob* e *hBlobDefault* referem-se a um bloco de memória que contém o seguinte:

- Um DWORD que contém o comprimento, em bytes, dos dados binários que se segue, seguido imediatamente por

- Um bloco de memória contendo os dados binários reais.

Observe `PX_Blob` que alocará a memória, usando a API Do Windows [GlobalAlloc,](/windows/win32/api/winbase/nf-winbase-globalalloc) ao carregar propriedades do tipo BLOB. Você é responsável por libertar essa memória. Portanto, o destruidor do seu controle deve ligar para [a GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree) em qualquer alça de propriedade do tipo BLOB para liberar qualquer memória alocada ao seu controle.

## <a name="px_bool"></a><a name="px_bool"></a>PX_Bool

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade do tipo BOOL.

```cpp
BOOL PX_Bool(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    BOOL& bValue);

BOOL PX_Bool(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    BOOL& bValue,
    BOOL bDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*bValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*bDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada pelo *bValue,* conforme apropriado. Se *bDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_color"></a><a name="px_color"></a>PX_Color

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade de OLE_COLOR tipo.

```cpp
BOOL PX_Color(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    OLE_COLOR& clrValue);

BOOL PX_Color(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    OLE_COLOR& clrValue,
    OLE_COLOR clrDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*clrValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*ClrDefault*<br/>
Valor padrão para a propriedade, conforme definido pelo desenvolvedor de controle.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada pelo *clrValue,* conforme apropriado. Se *clrDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_currency"></a><a name="px_currency"></a>PX_Currency

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade de **moeda**de tipo .

```cpp
BOOL PX_Currency(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CY& cyValue);

BOOL PX_Currency(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CY& cyValue,
    CY cyDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*cyValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*cyDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada pelo *cyValue,* conforme apropriado. Se *cyDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_datapath"></a><a name="px_datapath"></a>PX_DataPath

Chame essa função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade de caminho de dados do tipo [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md).

```cpp
BOOL PX_DataPath(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CDataPathProperty& dataPathProperty);

BOOL PX_DataPath(
    CPropExchange* pPX,
    CDataPathProperty& dataPathProperty);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*dataPathProperty*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

As propriedades do caminho de dados implementam propriedades de controle assíncronas. O valor da propriedade será lido ou gravado na variável referenciada pelo *dataPathProperty,* conforme apropriado.

## <a name="px_double"></a><a name="px_double"></a>PX_Double

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade do tipo **duplo**.

```cpp
BOOL PX_Double(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    double& doubleValue);

BOOL PX_Double(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    double& doubleValue,
    double doubleDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Doublevalue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*doubleDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada pelo *doubleValue,* conforme apropriado. Se *o DoubleDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_font"></a><a name="px_font"></a>PX_Font

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade da fonte do tipo.

```cpp
BOOL PX_Font(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CFontHolder& font,
    const FONTDESC FAR* pFontDesc = NULL,
    LPFONTDISP pFontDispAmbient = NULL);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Fonte*<br/>
Uma referência `CFontHolder` a um objeto que contém a propriedade da fonte.

*pFontDesc*<br/>
Um ponteiro `FONTDESC` para uma estrutura contendo os valores a serem usados na inicialização do estado padrão da propriedade da fonte, no caso em *que pFontDispAmbient* é NULL.

*Pfontdispambient*<br/>
Um ponteiro `IFontDisp` para a interface de uma fonte para usar na inicialização do estado padrão da propriedade da fonte.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido `font`ou `CFontHolder` escrito para , uma referência, quando apropriado. Se *pFontDesc* e *pFontDispAmbient* forem especificados, eles serão usados para inicializar o valor padrão da propriedade, quando necessário. Esses valores são usados se, por qualquer razão, o processo de serialização do controle falhar. Normalmente, você passa NULL para *pFontDesc* e `COleControl::AmbientFont` o valor ambiente devolvido por *pFontDispAmbient*. Observe que o objeto `COleControl::AmbientFont` de fonte retornado deve `IFontDisp::Release` ser liberado por uma chamada para a função membro.

## <a name="px_float"></a><a name="px_float"></a>PX_Float

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade do tipo **float**.

```cpp
BOOL PX_Float(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    float& floatValue);

BOOL PX_Float(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    float& floatValue,
    float floatDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*floatValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*floatDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *floatValue,* conforme apropriado. Se *floatDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_iunknown"></a><a name="px_iunknown"></a>PX_IUnknown

Chame essa função dentro `DoPropExchange` da função de membro do seu controle para `IUnknown`serializar ou inicializar uma propriedade representada por um objeto com uma interface derivada.

```cpp
BOOL PX_IUnknown(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    LPUNKNOWN& pUnk,
    REFIID iid,
    LPUNKNOWN pUnkDefault = NULL);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Punk*<br/>
Referência a uma variável que contenha a interface do objeto que representa o valor da propriedade.

*Iid*<br/>
Um ID de interface indicando qual interface do objeto de propriedade é usado pelo controle.

*pUnkDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou escrito para a variável referenciada por *pUnk,* conforme apropriado. Se *o pUnkDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_long"></a><a name="px_long"></a>PX_Long

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade de tipo **longo**.

```cpp
BOOL PX_Long(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    long& lValue);

BOOL PX_Long(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    long& lValue,
    long lDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Lvalue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*lDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *lValue,* conforme apropriado. Se *lDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_picture"></a><a name="px_picture"></a>PX_Picture

Chame essa função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade de imagem do seu controle.

```cpp
BOOL PX_Picture(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CPictureHolder& pict);

BOOL PX_Picture(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CPictureHolder& pict,
    CPictureHolder& pictDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Pict*<br/>
Referência a um objeto [CPictureHolder](../../mfc/reference/cpictureholder-class.md) onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*pictDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou escrito para a variável referenciada por *picto,* conforme apropriado. Se *pictDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_short"></a><a name="px_short"></a>PX_Short

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade do tipo **curto**.

```cpp
BOOL PX_Short(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    short& sValue);

BOOL PX_Short(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    short& sValue,
    short sDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*sValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*sDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada pelo *sValue,* conforme apropriado. Se *sDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_ulong"></a><a name="px_ulong"></a>PX_ULong

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade do tipo **ULONG**.

```cpp
BOOL PX_ULong(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    ULONG& ulValue);

BOOL PX_ULong(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    ULONG& ulValue,
    long ulDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
Nome da propriedade sendo trocada.

*ulValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*ulDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *ulValue,* conforme apropriado. Se *ulDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_ushort"></a><a name="px_ushort"></a>PX_UShort

Chame esta função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade do tipo **não assinado curto**.

```cpp
BOOL PX_UShort(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    USHORT& usValue);

BOOL PX_UShort(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    USHORT& usValue,
    USHORT usDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
Nome da propriedade sendo trocada.

*usValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*usDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *usValue,* conforme apropriado. Se *usDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="pxstring"></a><a name="px_string"></a>PXstring

Chame essa função dentro `DoPropExchange` da função de membro do seu controle para serializar ou inicializar uma propriedade de seqüência de caracteres.

```cpp
BOOL PXstring(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CString& strValue);

BOOL PXstring(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CString& strValue,
    CString strDefault);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*strValue*<br/>
Referência à variável onde a propriedade é armazenada (tipicamente uma variável membro da sua classe).

*strDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada pelo *strValue,* conforme apropriado. Se *o strDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, o processo de serialização do controle falhar.

## <a name="px_vbxfontconvert"></a><a name="px_vbxfontconvert"></a>PX_VBXFontConvert

Chame essa função dentro `DoPropExchange` da função de membro do seu controle para inicializar uma propriedade de fonte convertendo as propriedades relacionadas à fonte de um controle VBX.

```cpp
BOOL PX_VBXFontConvert(
    CPropExchange* pPX,
    CFontHolder& font);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente `DoPropExchange`passado como parâmetro para ).

*Fonte*<br/>
A propriedade fonte do controle OLE que conterá as propriedades relacionadas à fonte VBX convertidas.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

Esta função deve ser usada apenas por um controle OLE que é projetado como uma substituição direta para um controle VBX. Quando o ambiente de desenvolvimento Visual Basic converte um formulário contendo um controle VBX para `IDataObject::SetData` usar o controle OLE de substituição correspondente, ele chamará a função do controle, passando em um conjunto de propriedades que contém os dados de propriedade do controle VBX. Esta operação, por sua vez, `DoPropExchange` faz com que a função do controle seja invocada. `DoPropExchange`pode `PX_VBXFontConvert` chamar para converter as propriedades relacionadas à fonte do controle VBX (por exemplo, "FontName", "FontSize" e assim por diante) nos componentes correspondentes da propriedade de fonte do controle OLE.

`PX_VBXFontConvert`só deve ser chamado quando o controle está realmente sendo convertido a partir de um aplicativo de formulário VBX. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#14](../../mfc/codesnippet/cpp/persistence-of-ole-controls_1.cpp)]
[!code-cpp[NVC_MFCActiveXControl#15](../../mfc/codesnippet/cpp/persistence-of-ole-controls_2.cpp)]

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
