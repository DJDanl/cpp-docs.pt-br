---
title: Persistência de controles OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE controls [MFC], persistence
- persistence, OLE controls
ms.assetid: 64f8dc80-f110-41af-b3ea-14948f6bfdf7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e84e26bae83bd131b53d10e4561ddb60854a8a5e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="persistence-of-ole-controls"></a>Persistência de controles OLE
Um recurso de controles OLE é propriedade persistência (ou serialização), que permite que o controle OLE ler ou gravar valores de propriedade para e de um arquivo ou fluxo. Um aplicativo de contêiner pode usar serialização para armazenar valores de propriedade do controle, mesmo depois que o aplicativo foi destruído o controle. Os valores de propriedade do controle OLE, em seguida, podem ser lidos do arquivo ou quando uma nova instância do controle de fluxo é criado em um momento posterior.  
  
### <a name="persistence-of-ole-controls"></a>Persistência de controles OLE  
  
|||  
|-|-|  
|[PX_Blob](#px_blob)|Troca de uma propriedade de controle que armazena dados de objeto binário grande (BLOB).|  
|[PX_Bool](#px_bool)|Troca de uma propriedade de controle do tipo **BOOL**.|  
|[PX_Color](#px_color)|Troca de uma propriedade de cor de um controle.|  
|[PX_Currency](#px_currency)|Troca de uma propriedade de controle do tipo **CY**.|  
|[PX_DataPath](#px_datapath)|Troca de uma propriedade de controle do tipo `CDataPathProperty`.|  
|[PX_Double](#px_double)|Troca de uma propriedade de controle do tipo **duplo**.|  
|[PX_Font](#px_font)|Troca de uma propriedade de fonte de um controle.|  
|[PX_Float](#px_float)|Troca de uma propriedade de controle do tipo **float**.|  
|[PX_IUnknown](#px_iunknown)|Troca de uma propriedade de controle do tipo indefinido.|  
|[PX_Long](#px_long)|Troca de uma propriedade de controle do tipo **longo**.|  
|[PX_Picture](#px_picture)|Troca de uma propriedade de imagem de um controle.|  
|[PX_Short](#px_short)|Troca de uma propriedade de controle do tipo **curto**.|  
|[PX_ULong](#px_ulong)|Troca de uma propriedade de controle do tipo **ULONG**.|  
|[PX_UShort](#px_ushort)|Troca de uma propriedade de controle do tipo **USHORT**.|  
|[PXstring](#px_string)|Troca de uma propriedade de controle de cadeia de caracteres.|  
|[PX_VBXFontConvert](#px_vbxfontconvert)|Troca VBX relacionadas à fonte propriedades de um controle em uma propriedade de fonte de controle OLE.|  
  
 Além disso, o `AfxOleTypeMatchGuid` função global é fornecida para testar uma correspondência entre um `TYPEDESC` e um GUID especificado.  
  
##  <a name="px_blob"></a>  PX_Blob  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a uma propriedade que armazena dados de objeto binário grande (BLOB).  
  
```  
 
BOOL  
PX_Blob(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    HGLOBAL& 
hBlob  ,  
    HGLOBAL 
hBlobDefault  
= NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `hBlob`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `hBlobDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado para a variável referenciada por `hBlob`, conforme apropriado. Essa variável deve ser inicializada para **nulo** antes de chamar inicialmente `PX_Blob` pela primeira vez (normalmente, isso pode ser feito no construtor do controle). Se `hBlobDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de inicialização ou de serialização do controle falhar.  
  
 Os identificadores de `hBlob` e `hBlobDefault` se referir a um bloco de memória que contém o seguinte:  
  
-   Um `DWORD` que contém o comprimento, em bytes, dos dados binários que segue, seguido imediatamente por  
  
-   Um bloco de memória que contém os dados binários reais.  
  
 Observe que `PX_Blob` alocará memória, usando o Windows [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) API, ao carregar as propriedades de tipo BLOB. Você é responsável pela liberação de memória. Portanto, o destruidor de seu controle deve chamar [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579) em qualquer propriedade de tipo de BLOB identificadores para liberar até toda a memória alocada para o controle.  
  
##  <a name="px_bool"></a>  PX_Bool  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **BOOL**.  
  
```  
 
BOOL  
PX_Bool(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    BOOL& bValue);

BOOL  
PX_Bool(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    BOOL& 
bValue  ,  
    BOOL bDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `bValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `bDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado para a variável referenciada por `bValue`, conforme apropriado. Se `bDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_color"></a>  PX_Color  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **OLE_COLOR**.  
  
```  
 
BOOL PX_Color(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    OLE_COLOR& clrValue);

BOOL PX_Color(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    OLE_COLOR& 
clrValue  ,  
    OLE_COLOR 
clrDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `clrValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `clrDefault`  
 Valor padrão para a propriedade, conforme definido pelo desenvolvedor do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado para a variável referenciada por `clrValue`, conforme apropriado. Se `clrDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_currency"></a>  PX_Currency  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **moeda**.  
  
```  
 
BOOL  
PX_Currency(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CY& cyValue);

BOOL  
PX_Currency(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CY& 
cyValue  ,  
    CY cyDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `cyValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `cyDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado para a variável referenciada por `cyValue`, conforme apropriado. Se `cyDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_datapath"></a>  PX_DataPath  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do caminho de dados do tipo [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md).  
  
```  
 
BOOL  
PX_DataPath(
    CPropExchange* 
pPX,  
    LPCTSTR 
pszPropName,  
    CDataPathProperty& dataPathProperty);

BOOL  
PX_DataPath(
    CPropExchange* 
pPX,  
    CDataPathProperty& dataPathProperty);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `dataPathProperty`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Propriedades de caminho de dados implementam propriedades de controle assíncrono. O valor da propriedade será ser lido ou gravado para a variável referenciada por `dataPathProperty`, conforme apropriado.  
  
##  <a name="px_double"></a>  PX_Double  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **duplo**.  
  
```  
 
BOOL  
PX_Double(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    double& doubleValue);

BOOL  
PX_Double(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    double& 
doubleValue  ,  
    double doubleDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `doubleValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `doubleDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `doubleValue`, conforme apropriado. Se `doubleDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_font"></a>  PX_Font  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a uma propriedade de fonte de tipo.  
  
```  
 
BOOL  
PX_Font(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CFontHolder& 
font  ,  
    const 
FONTDESC  
FAR* 
pFontDesc  
= 
NULL,  
    LPFONTDISP 
pFontDispAmbient  
= NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `font`  
 Uma referência a um `CFontHolder` objeto que contém a propriedade de fonte.  
  
 `pFontDesc`  
 Um ponteiro para um **FONTDESC** estrutura que contém os valores a serem usados ao inicializar o estado padrão da propriedade font, no caso onde `pFontDispAmbient` é **nulo**.  
  
 `pFontDispAmbient`  
 Um ponteiro para o **IFontDisp** interface de uma fonte a ser usado ao inicializar o estado padrão da propriedade font.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lida ou gravado para `font`, um `CFontHolder` referência, quando apropriado. Se `pFontDesc` e `pFontDispAmbient` forem especificados, eles são usados para inicializar o valor da propriedade padrão, quando necessário. Esses valores são usados se, por algum motivo, o processo de serialização do controle falhar. Normalmente, você passa **nulo** para `pFontDesc` e o valor de ambiente retornado por `COleControl::AmbientFont` para `pFontDispAmbient`. Observe que o objeto de fonte retornado por `COleControl::AmbientFont` devem ser liberados por uma chamada para o **IFontDisp::Release** função de membro.  
  
##  <a name="px_float"></a>  PX_Float  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **float**.  
  
```  
 
BOOL  
PX_Float(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    float& floatValue);

BOOL  
PX_Float(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    float& 
floatValue  ,  
    float floatDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `floatValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `floatDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `floatValue`, conforme apropriado. Se `floatDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_iunknown"></a>  PX_IUnknown  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade representada por um objeto com um **IUnknown**-interface derivada.  
  
```  
 
BOOL  
PX_IUnknown(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    LPUNKNOWN& 
pUnk  ,  
    REFIID 
iid  ,  
    LPUNKNOWN 
pUnkDefault  
= NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 *pUnk*  
 Referência a uma variável que contém a interface do objeto que representa o valor da propriedade.  
  
 `iid`  
 Uma ID de interface que indica qual interface do objeto de propriedade é usada pelo controle.  
  
 `pUnkDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por *pUnk*, conforme apropriado. Se `pUnkDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_long"></a>  PX_Long  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **longo**.  
  
```  
 
BOOL  
PX_Long(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    long& lValue);

BOOL  
PX_Long(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    long& 
lValue  ,  
    long lDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `lValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `lDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `lValue`, conforme apropriado. Se `lDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_picture"></a>  PX_Picture  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro ao serializar ou inicializar a uma propriedade de imagem do seu controle.  
  
```  
 
BOOL  
PX_Picture(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CPictureHolder& pict);

BOOL  
PX_Picture(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CPictureHolder& 
pict  ,  
    CPictureHolder& pictDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `pict`  
 Referência a um [CPictureHolder](../../mfc/reference/cpictureholder-class.md) objeto onde a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `pictDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `pict`, conforme apropriado. Se `pictDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_short"></a>  PX_Short  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **curto**.  
  
```  
 
BOOL  
PX_Short(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    short& sValue);

BOOL  
PX_Short(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    short& 
sValue  ,  
    short sDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `sValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `sDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `sValue`, conforme apropriado. Se `sDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_ulong"></a>  PX_ULong  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo **ULONG**.  
  
```  
 
BOOL  
PX_ULong(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    ULONG& ulValue);

BOOL  
PX_ULong(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    ULONG& 
ulValue  ,  
    long ulDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 Nome da propriedade que está sendo trocada.  
  
 `ulValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `ulDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `ulValue`, conforme apropriado. Se `ulDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_ushort"></a>  PX_UShort  
 Chamar essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar a propriedade do tipo `unsigned` **curto**.  
  
```  
 
BOOL  
PX_UShort(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    USHORT& usValue);

BOOL  
PX_UShort(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    USHORT& 
usValue  ,  
    USHORT usDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 Nome da propriedade que está sendo trocada.  
  
 *usValue*  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 *usDefault*  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por *usValue*, conforme apropriado. Se *usDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_string"></a>  PXstring  
 Chamar essa função dentro do controle **DoPropExchange** a função de membro ao serializar ou inicializar a uma propriedade de cadeia de caracteres.  
  
```  
 
BOOL  
PXstring(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CString& strValue);

BOOL  
PXstring(
    CPropExchange* 
pPX  ,  
    LPCTSTR 
pszPropName  ,  
    CString& 
strValue  ,  
    CString strDefault);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade que está sendo trocado.  
  
 `strValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro de classe).  
  
 `strDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `strValue`, conforme apropriado. Se `strDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="px_vbxfontconvert"></a>  PX_VBXFontConvert  
 Chamar essa função dentro do controle `DoPropExchange` função de membro para inicializar uma propriedade de fonte, convertendo VBX relacionadas à fonte propriedades de um controle.  
  
```  
 
BOOL  
PX_VBXFontConvert(
    CPropExchange* 
pPX  ,  
    CFontHolder& font);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (geralmente é passado como um parâmetro para `DoPropExchange`).  
  
 `font`  
 A propriedade de fonte do controle OLE que conterá as propriedades de fonte relacionadas de VBX convertidas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser usada somente por um controle OLE que foi projetado como uma substituição direta para um controle VBX. Quando o ambiente de desenvolvimento do Visual Basic converte um formulário que contém um controle VBX para usar a controle OLE de substituição correspondente, ele chamará o controle **IDataObject::SetData** função, passando uma propriedade definida que contém dados de propriedade do controle VBX. Essa operação, por sua vez, faz com que o controle `DoPropExchange` função a ser invocado. `DoPropExchange` pode chamar `PX_VBXFontConvert` para converter as propriedades relacionadas a fonte do controle VBX (por exemplo, "FontName," "FontSize", e assim por diante) para os componentes correspondentes das propriedade de fonte do controle OLE.  
  
 `PX_VBXFontConvert` só deve ser chamado quando o controle, na verdade, está sendo convertido em um aplicativo de forma VBX. Por exemplo:  
  
 [!code-cpp[NVC_MFCActiveXControl#14](../../mfc/codesnippet/cpp/persistence-of-ole-controls_1.cpp)]  
[!code-cpp[NVC_MFCActiveXControl#15](../../mfc/codesnippet/cpp/persistence-of-ole-controls_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
