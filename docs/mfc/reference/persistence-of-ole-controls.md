---
title: Persistência de controles OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE controls [MFC], persistence
- persistence, OLE controls
ms.assetid: 64f8dc80-f110-41af-b3ea-14948f6bfdf7
ms.openlocfilehash: f3ef5a1f465cc478b429b9fa41d6478f22030a8a
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843606"
---
# <a name="persistence-of-ole-controls"></a>Persistência de controles OLE

Uma funcionalidade dos controles OLE é a persistência de propriedade (ou serialização), que permite que o controle OLE leia ou grave valores de propriedade de e para um arquivo ou fluxo. Um aplicativo de contêiner pode usar a serialização para armazenar os valores de propriedade de um controle mesmo depois que o aplicativo tiver destruído o controle. Os valores de Propriedade do controle OLE podem ser lidos do arquivo ou do fluxo quando uma nova instância do controle é criada posteriormente.

### <a name="persistence-of-ole-controls"></a>Persistência de controles OLE

|Nome|Descrição|
|-|-|
|[PX_Blob](#px_blob)|Troca uma propriedade de controle que armazena dados BLOB (objeto binário grande).|
|[PX_Bool](#px_bool)|Troca uma propriedade de controle do tipo **bool**.|
|[PX_Color](#px_color)|Troca uma propriedade de cor de um controle.|
|[PX_Currency](#px_currency)|Troca uma propriedade de controle do tipo **CY**.|
|[PX_DataPath](#px_datapath)|Troca uma propriedade de controle do tipo `CDataPathProperty` .|
|[PX_Double](#px_double)|Troca uma propriedade de controle do tipo **`double`** .|
|[PX_Font](#px_font)|Troca uma propriedade de fonte de um controle.|
|[PX_Float](#px_float)|Troca uma propriedade de controle do tipo **`float`** .|
|[PX_IUnknown](#px_iunknown)|Troca uma propriedade de controle de tipo indefinido.|
|[PX_Long](#px_long)|Troca uma propriedade de controle do tipo **`long`** .|
|[PX_Picture](#px_picture)|Troca uma propriedade de imagem de um controle.|
|[PX_Short](#px_short)|Troca uma propriedade de controle do tipo **`short`** .|
|[PX_ULong](#px_ulong)|Troca uma propriedade de controle do tipo **ULONG**.|
|[PX_UShort](#px_ushort)|Troca uma propriedade de controle do tipo **UShort**.|
|[PXstring](#px_string)|Troca uma propriedade de controle de cadeia de caracteres.|
|[PX_VBXFontConvert](#px_vbxfontconvert)|Troca as propriedades relacionadas à fonte de um controle VBX em uma propriedade de fonte de controle OLE.|

Além disso, a `AfxOleTypeMatchGuid` função global é fornecida para testar uma correspondência entre um TYPEDESC e um GUID específico.

## <a name="px_blob"></a><a name="px_blob"></a> PX_Blob

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade que armazena dados BLOB (objeto binário grande).

```cpp
BOOL PX_Blob(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    HGLOBAL& hBlob,
    HGLOBAL hBlobDefault = NULL);
```

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*hBlob*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*hBlobDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada por *hBlob*, conforme apropriado. Essa variável deve ser inicializada como NULL antes de chamar inicialmente pela `PX_Blob` primeira vez (normalmente, isso pode ser feito no construtor do controle). Se *hBlobDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por qualquer motivo, o processo de inicialização ou de serialização do controle falhar.

Os identificadores *hBlob* e *hBlobDefault* referem-se a um bloco de memória que contém o seguinte:

- Um DWORD que contém o comprimento, em bytes, dos dados binários a seguir, seguido imediatamente por

- Um bloco de memória que contém os dados binários reais.

Observe que `PX_Blob` o alocará memória, usando a API [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) do Windows, ao carregar Propriedades do tipo BLOB. Você é responsável por liberar essa memória. Portanto, o destruidor do seu controle deve chamar [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree) em qualquer identificador de propriedade de tipo blob para liberar qualquer memória alocada para seu controle.

## <a name="px_bool"></a><a name="px_bool"></a> PX_Bool

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade do tipo bool.

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*bValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*bDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada por *bValue*, conforme apropriado. Se *bDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_color"></a><a name="px_color"></a> PX_Color

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo OLE_COLOR.

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*clrValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*clrDefault*<br/>
Valor padrão da propriedade, conforme definido pelo desenvolvedor do controle.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada por *clrValue*, conforme apropriado. Se *clrDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_currency"></a><a name="px_currency"></a> PX_Currency

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo **Currency**.

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*cyValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*cyDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade será lido ou gravado na variável referenciada por *cyValue*, conforme apropriado. Se *cyDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_datapath"></a><a name="px_datapath"></a> PX_DataPath

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade de caminho de dados do tipo [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md).

```cpp
BOOL PX_DataPath(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CDataPathProperty& dataPathProperty);

BOOL PX_DataPath(
    CPropExchange* pPX,
    CDataPathProperty& dataPathProperty);
```

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*dataPathProperty*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Propriedades de caminho de dados implementam Propriedades de controle assíncrono. O valor da propriedade será lido ou gravado na variável referenciada por *dataPathProperty*, conforme apropriado.

## <a name="px_double"></a><a name="px_double"></a> PX_Double

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo **`double`** .

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*duplovalue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*doubleDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *doubleValue*, conforme apropriado. Se *doubleDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_font"></a><a name="px_font"></a> PX_Font

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo Font.

```cpp
BOOL PX_Font(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CFontHolder& font,
    const FONTDESC FAR* pFontDesc = NULL,
    LPFONTDISP pFontDispAmbient = NULL);
```

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*la*<br/>
Uma referência a um `CFontHolder` objeto que contém a propriedade Font.

*pFontDesc*<br/>
Um ponteiro para uma `FONTDESC` estrutura que contém os valores a serem usados na inicialização do estado padrão da propriedade Font, no caso em que *PFONTDISPAMBIENT* é nulo.

*pFontDispAmbient*<br/>
Um ponteiro para a `IFontDisp` interface de uma fonte a ser usada na inicialização do estado padrão da propriedade Font.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado em `font` uma `CFontHolder` referência, quando apropriado. Se *pFontDesc* e *pFontDispAmbient* forem especificados, eles serão usados para inicializar o valor padrão da propriedade, quando necessário. Esses valores serão usados se, por algum motivo, o processo de serialização do controle falhar. Normalmente, você passa nulo para *pFontDesc* e o valor de ambiente retornado por `COleControl::AmbientFont` para *pFontDispAmbient*. Observe que o objeto de fonte retornado por `COleControl::AmbientFont` deve ser liberado por uma chamada para a `IFontDisp::Release` função membro.

## <a name="px_float"></a><a name="px_float"></a> PX_Float

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo **`float`** .

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*floatValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*floatDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *floatValue*, conforme apropriado. Se *floatDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_iunknown"></a><a name="px_iunknown"></a> PX_IUnknown

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade representada por um objeto que tenha uma `IUnknown` interface derivada.

```cpp
BOOL PX_IUnknown(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    LPUNKNOWN& pUnk,
    REFIID iid,
    LPUNKNOWN pUnkDefault = NULL);
```

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*pUnk*<br/>
Referência a uma variável que contém a interface do objeto que representa o valor da propriedade.

*IID*<br/>
Uma ID de interface que indica qual interface do objeto de propriedade é usada pelo controle.

*pUnkDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *punk*, conforme apropriado. Se *pUnkDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_long"></a><a name="px_long"></a> PX_Long

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo **`long`** .

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*lValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*lDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *lvalue*, conforme apropriado. Se *lDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_picture"></a><a name="px_picture"></a> PX_Picture

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade de imagem do seu controle.

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*otimizar*<br/>
Referência a um objeto [CPictureHolder](../../mfc/reference/cpictureholder-class.md) em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*pictDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *PICT*, conforme apropriado. Se *pictDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_short"></a><a name="px_short"></a> PX_Short

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo **`short`** .

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*sValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*sDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *sValue*, conforme apropriado. Se *sDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_ulong"></a><a name="px_ulong"></a> PX_ULong

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade do tipo **ULONG**.

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
Nome da propriedade que está sendo trocada.

*ulValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*ulDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *ulValue*, conforme apropriado. Se *ulDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_ushort"></a><a name="px_ushort"></a> PX_UShort

Chame essa função na `DoPropExchange` função de membro do controle para serializar ou inicializar uma propriedade do tipo **`unsigned short`** .

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
Nome da propriedade que está sendo trocada.

*usValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*usDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *usValue*, conforme apropriado. Se *usDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="pxstring"></a><a name="px_string"></a> PXstring

Chame essa função na função de membro do controle `DoPropExchange` para serializar ou inicializar uma propriedade de cadeia de caracteres.

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

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*strValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*strDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado na variável referenciada por *bervalue*, conforme apropriado. Se *strDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por algum motivo, o processo de serialização do controle falhar.

## <a name="px_vbxfontconvert"></a><a name="px_vbxfontconvert"></a> PX_VBXFontConvert

Chame essa função na função de membro do controle `DoPropExchange` para inicializar uma propriedade de fonte convertendo as propriedades relacionadas à fonte de um controle VBX.

```cpp
BOOL PX_VBXFontConvert(
    CPropExchange* pPX,
    CFontHolder& font);
```

### <a name="parameters"></a>parâmetros

*pPX*<br/>
Ponteiro para o objeto [CPropExchange](../../mfc/reference/cpropexchange-class.md) (normalmente passado como um parâmetro para `DoPropExchange` ).

*la*<br/>
A propriedade Font do controle OLE que conterá as propriedades relacionadas à fonte do VBX convertidas.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Essa função deve ser usada somente por um controle OLE criado como uma substituição direta para um controle VBX. Quando o ambiente de desenvolvimento de Visual Basic converte um formulário que contém um controle VBX para usar o controle OLE substituto correspondente, ele chamará a função do controle `IDataObject::SetData` , passando um conjunto de propriedades que contém os dados de Propriedade do controle VBX. Essa operação, por sua vez, faz com que a função do controle `DoPropExchange` seja invocada. `DoPropExchange` pode chamar `PX_VBXFontConvert` para converter as propriedades relacionadas à fonte do controle VBX (por exemplo, "NomeDaFonte," "FontSize" e assim por diante) nos componentes correspondentes da propriedade Font do controle OLE.

`PX_VBXFontConvert` Só deve ser chamado quando o controle está realmente sendo convertido de um aplicativo de formulário do VBX. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#14](../../mfc/codesnippet/cpp/persistence-of-ole-controls_1.cpp)]
[!code-cpp[NVC_MFCActiveXControl#15](../../mfc/codesnippet/cpp/persistence-of-ole-controls_2.cpp)]

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
