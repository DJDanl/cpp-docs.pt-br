---
title: Persistência de controles OLE
ms.date: 11/04/2016
helpviewer_keywords:
- OLE controls [MFC], persistence
- persistence, OLE controls
ms.assetid: 64f8dc80-f110-41af-b3ea-14948f6bfdf7
ms.openlocfilehash: 639a5a98da03307e3edf22deb6d32956c3f73374
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611772"
---
# <a name="persistence-of-ole-controls"></a>Persistência de controles OLE

Um recurso de controles OLE é propriedade persistência (serialização ou), que permite que o controle OLE ler ou gravar valores de propriedade de e para um arquivo ou fluxo. Um aplicativo de contêiner pode usar a serialização para armazenar valores de propriedade do controle, mesmo depois que o aplicativo foi destruído o controle. Os valores de propriedade do controle OLE, em seguida, podem ser lidos do arquivo ou fluxo quando uma nova instância do controle é criado em um momento posterior.

### <a name="persistence-of-ole-controls"></a>Persistência de controles OLE

|||
|-|-|
|[PX_Blob](#px_blob)|Troca de uma propriedade de controle que armazena dados de objeto binário grande (BLOB).|
|[PX_Bool](#px_bool)|Troca de uma propriedade de controle do tipo **BOOL**.|
|[PX_Color](#px_color)|Troca de uma propriedade de cor de um controle.|
|[PX_Currency](#px_currency)|Troca de uma propriedade de controle do tipo **CY**.|
|[PX_DataPath](#px_datapath)|Troca de uma propriedade de controle do tipo `CDataPathProperty`.|
|[PX_Double](#px_double)|Troca de uma propriedade de controle do tipo **duplas**.|
|[PX_Font](#px_font)|Troca de uma propriedade de fonte de um controle.|
|[PX_Float](#px_float)|Troca de uma propriedade de controle do tipo **float**.|
|[PX_IUnknown](#px_iunknown)|Troca de uma propriedade de controle do tipo indefinido.|
|[PX_Long](#px_long)|Troca de uma propriedade de controle do tipo **longo**.|
|[PX_Picture](#px_picture)|Troca de uma propriedade de imagem de um controle.|
|[PX_Short](#px_short)|Troca de uma propriedade de controle do tipo **curto**.|
|[PX_ULong](#px_ulong)|Troca de uma propriedade de controle do tipo **ULONG**.|
|[PX_UShort](#px_ushort)|Troca de uma propriedade de controle do tipo **USHORT**.|
|[PXstring](#px_string)|Troca de uma propriedade de controle de cadeia de caracteres.|
|[PX_VBXFontConvert](#px_vbxfontconvert)|Troca VBX relacionadas a fonte propriedades de um controle em uma propriedade de fonte de controle OLE.|

Além disso, o `AfxOleTypeMatchGuid` função global é fornecida para testar uma correspondência entre TYPEDESC e um GUID específico.

##  <a name="px_blob"></a>  PX_Blob

Chame essa função dentro do seu controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade que armazena dados de objeto binário grande (BLOB).

```
BOOL PX_Blob(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    HGLOBAL& hBlob,
    HGLOBAL hBlobDefault = NULL);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*hBlob*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*hBlobDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade será ser lidos ou gravado para a variável referenciada por *hBlob*, conforme apropriado. Essa variável deve ser inicializada como NULL antes de chamar inicialmente `PX_Blob` pela primeira vez (normalmente, isso pode ser feito no construtor do controle). Se *hBlobDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização ou de inicialização do controle falhar.

As alças *hBlob* e *hBlobDefault* se referir a um bloco de memória que contém o seguinte:

- Um DWORD que contém o comprimento, em bytes, dos dados binários que segue, seguida imediatamente de

- Um bloco de memória que contém os dados binários reais.

Observe que `PX_Blob` alocará memória, usando o Windows [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc) API, ao carregar as propriedades de tipo de BLOB. Você é responsável por liberar essa memória. Portanto, o destruidor de seu controle deve chamar [GlobalFree](/windows/desktop/api/winbase/nf-winbase-globalfree) em qualquer propriedade de tipo de BLOB alças para liberar até toda a memória alocada para o seu controle.

##  <a name="px_bool"></a>  PX_Bool

Chame essa função dentro do seu controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo BOOL.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*bValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*bDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade será ser lidos ou gravado para a variável referenciada por *bValue*, conforme apropriado. Se *bNível padrão* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_color"></a>  PX_Color

Chame essa função dentro do seu controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo OLE_COLOR.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*clrValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*clrDefault*<br/>
Valor padrão para a propriedade, conforme definido pelo desenvolvedor do controle.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade será ser lidos ou gravado para a variável referenciada por *clrValue*, conforme apropriado. Se *clrDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_currency"></a>  PX_Currency

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **moeda**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*cyValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*cyDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade será ser lidos ou gravado para a variável referenciada por *cyValue*, conforme apropriado. Se *cyDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_datapath"></a>  PX_DataPath

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade de caminho de dados do tipo [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md).

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*dataPathProperty*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

Propriedades de caminho de dados implementam propriedades de controle assíncrono. O valor da propriedade será ser lidos ou gravado para a variável referenciada por *dataPathProperty*, conforme apropriado.

##  <a name="px_double"></a>  PX_Double

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **duplo**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*doubleValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*doubleDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *doubleValue*, conforme apropriado. Se *doubleDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_font"></a>  PX_Font

Chame essa função dentro do seu controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade de fonte de tipo.

```
BOOL PX_Font(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    CFontHolder& font,
    const FONTDESC FAR* pFontDesc = NULL,
    LPFONTDISP pFontDispAmbient = NULL);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*font*<br/>
Uma referência a um `CFontHolder` objeto que contém a propriedade de fonte.

*pFontDesc*<br/>
Um ponteiro para um `FONTDESC` estrutura que contém os valores a serem usados ao inicializar o estado padrão da propriedade da fonte, no caso em que *pFontDispAmbient* é NULL.

*pFontDispAmbient*<br/>
Um ponteiro para o `IFontDisp` interface de uma fonte para usar ao inicializar o estado padrão da propriedade da fonte.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lida ou gravado para `font`, um `CFontHolder` fazem referência, quando apropriado. Se *pFontDesc* e *pFontDispAmbient* forem especificados, eles são usados para inicializar o valor da propriedade padrão, quando necessário. Esses valores são usados se, por algum motivo, o processo de serialização do controle falhar. Normalmente, passar NULL para *pFontDesc* e o valor de ambiente retornado por `COleControl::AmbientFont` para *pFontDispAmbient*. Observe que o objeto de fonte retornado por `COleControl::AmbientFont` devem ser liberados por uma chamada para o `IFontDisp::Release` função de membro.

##  <a name="px_float"></a>  PX_Float

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **float**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*floatValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*floatDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *floatValue*, conforme apropriado. Se *floatDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_iunknown"></a>  PX_IUnknown

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade representada por um objeto tendo um `IUnknown`-interface derivada.

```
BOOL PX_IUnknown(
    CPropExchange* pPX,
    LPCTSTR pszPropName,
    LPUNKNOWN& pUnk,
    REFIID iid,
    LPUNKNOWN pUnkDefault = NULL);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*pUnk*<br/>
Referência a uma variável que contém a interface do objeto que representa o valor da propriedade.

*iid*<br/>
Uma ID de interface que indica qual interface do objeto de propriedade é usada pelo controle.

*pUnkDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *pUnk*, conforme apropriado. Se *pUnkDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_long"></a>  PX_Long

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **longo**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*lValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*lDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *lValue*, conforme apropriado. Se *lDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_picture"></a>  PX_Picture

Chame essa função dentro do seu controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade de imagem do seu controle.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*pict*<br/>
Referência a um [CPictureHolder](../../mfc/reference/cpictureholder-class.md) objeto em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*pictDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *pict*, conforme apropriado. Se *pictDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_short"></a>  PX_Short

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **curto**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*sValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*sDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *sValue*, conforme apropriado. Se *sDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_ulong"></a>  PX_ULong

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **ULONG**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
Nome da propriedade sendo trocada.

*ulValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*ulDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *ulValue*, conforme apropriado. Se *ulDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_ushort"></a>  PX_UShort

Chame essa função dentro do seu controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade do tipo **unsigned short**.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
Nome da propriedade sendo trocada.

*usValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*usDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *usValue*, conforme apropriado. Se *usDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_string"></a>  PXstring

Chame essa função dentro do seu controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade de cadeia de caracteres.

```
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
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*pszPropName*<br/>
O nome da propriedade sendo trocado.

*strValue*<br/>
Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).

*strDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado para a variável referenciada por *strValue*, conforme apropriado. Se *strDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.

##  <a name="px_vbxfontconvert"></a>  PX_VBXFontConvert

Chame essa função dentro do seu controle `DoPropExchange` função de membro para inicializar uma propriedade de fonte, convertendo as propriedades relacionadas a fonte de um controle VBX.

```
BOOL PX_VBXFontConvert(
    CPropExchange* pPX,
    CFontHolder& font);
```

### <a name="parameters"></a>Parâmetros

*pPX*<br/>
Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).

*font*<br/>
A propriedade de fonte do controle OLE que contém as propriedades de fonte relacionadas do VBX convertidas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o exchange foi bem-sucedida; 0 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

Essa função deve ser usada somente por um controle OLE que foi projetado como uma substituição direta para um controle VBX. Quando o ambiente de desenvolvimento do Visual Basic converte um formulário que contenha um controle VBX para usar a controle OLE de substituição correspondente, ele chamará o controle `IDataObject::SetData` função, passando um conjunto de propriedades que contém dados de propriedade do controle VBX. Essa operação, por sua vez, faz com que o controle `DoPropExchange` função a ser invocada. `DoPropExchange` pode chamar `PX_VBXFontConvert` para converter as propriedades de relacionadas a fonte do controle VBX (por exemplo, "FontName," "FontSize", e assim por diante) para os componentes correspondentes das propriedade de fonte do controle OLE.

`PX_VBXFontConvert` só deve ser chamado quando o controle, na verdade, está sendo convertido de um aplicativo de formulário VBX. Por exemplo:

[!code-cpp[NVC_MFCActiveXControl#14](../../mfc/codesnippet/cpp/persistence-of-ole-controls_1.cpp)]
[!code-cpp[NVC_MFCActiveXControl#15](../../mfc/codesnippet/cpp/persistence-of-ole-controls_2.cpp)]

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
