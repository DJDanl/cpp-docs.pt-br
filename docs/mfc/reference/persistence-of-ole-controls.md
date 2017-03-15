---
title: "Persistência de controles OLE | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.ole
dev_langs:
- C++
helpviewer_keywords:
- OLE controls, persistence
- persistence, OLE controls
ms.assetid: 64f8dc80-f110-41af-b3ea-14948f6bfdf7
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b8bbf72a1ea16b37dabf88c5d41a34b1a03ba0d1
ms.lasthandoff: 02/25/2017

---
# <a name="persistence-of-ole-controls"></a>Persistência de controles OLE
Um recurso de controles OLE é propriedade persistência (serialização), que permite que o controle OLE ler ou gravar valores de propriedade para e de um arquivo ou fluxo. Um aplicativo de contêiner pode usar serialização para armazenar valores de propriedade do controle, mesmo depois que o aplicativo foi destruído o controle. Os valores de propriedade do controle OLE podem ser lidos do arquivo ou fluxo quando uma nova instância do controle é criado em um momento posterior.  
  
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
  
##  <a name="a-namepxbloba--pxblob"></a><a name="px_blob"></a>PX_Blob  
 Chame essa função dentro do controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade que armazena dados de objeto binário grande (BLOB).  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `hBlob`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `hBlobDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado na variável referenciada por `hBlob`, conforme apropriado. Essa variável deve ser inicializada para **nulo** antes de chamar inicialmente `PX_Blob` pela primeira vez (normalmente, isso pode ser feito no construtor do controle). Se `hBlobDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de inicialização ou a serialização do controle falhar.  
  
 Os identificadores de `hBlob` e `hBlobDefault` se referir a um bloco de memória que contém o seguinte:  
  
-   Um `DWORD` que contém o comprimento, em bytes, dos dados binários que segue, seguido imediatamente por  
  
-   Um bloco de memória que contém os dados binários reais.  
  
 Observe que `PX_Blob` alocará memória, usando o Windows [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) API, ao carregar as propriedades de tipo BLOB. Você é responsável por liberar essa memória. Portanto, o destruidor de seu controle deve chamar [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579) em qualquer propriedade do tipo BLOB identificadores para liberar até toda a memória alocada para o controle.  
  
##  <a name="a-namepxboola--pxbool"></a><a name="px_bool"></a>PX_Bool  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **BOOL**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `bValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `bDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado na variável referenciada por `bValue`, conforme apropriado. Se `bDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxcolora--pxcolor"></a><a name="px_color"></a>PX_Color  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **OLE_COLOR**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `clrValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `clrDefault`  
 Valor padrão para a propriedade, conforme definido pelo desenvolvedor do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado na variável referenciada por `clrValue`, conforme apropriado. Se `clrDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxcurrencya--pxcurrency"></a><a name="px_currency"></a>PX_Currency  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **moeda**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `cyValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `cyDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade será ser lido ou gravado na variável referenciada por `cyValue`, conforme apropriado. Se `cyDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxdatapatha--pxdatapath"></a><a name="px_datapath"></a>PX_DataPath  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade de caminho de dados do tipo [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md).  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `dataPathProperty`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Propriedades do caminho de dados implementam propriedades de controle assíncrono. O valor da propriedade será ser lido ou gravado na variável referenciada por `dataPathProperty`, conforme apropriado.  
  
##  <a name="a-namepxdoublea--pxdouble"></a><a name="px_double"></a>PX_Double  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **duplo**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `doubleValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `doubleDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `doubleValue`, conforme apropriado. Se `doubleDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxfonta--pxfont"></a><a name="px_font"></a>PX_Font  
 Chame essa função dentro do controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade de fonte de tipo.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `font`  
 Uma referência a um `CFontHolder` objeto que contém a propriedade font.  
  
 `pFontDesc`  
 Um ponteiro para um **FONTDESC** estrutura que contém os valores a serem usados ao inicializar o estado padrão da propriedade font, no caso onde `pFontDispAmbient` é **nulo**.  
  
 `pFontDispAmbient`  
 Um ponteiro para o **IFontDisp** interface de uma fonte a ser usada ao inicializar o estado padrão da propriedade font.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado em `font`, um `CFontHolder` referência, quando apropriado. Se `pFontDesc` e `pFontDispAmbient` são especificados, eles são usados para inicializar o valor da propriedade padrão, quando necessário. Esses valores são usados se, por algum motivo, o processo de serialização do controle falhar. Normalmente, você passa **nulo** para `pFontDesc` e o ambiente valor retornado por `COleControl::AmbientFont` para `pFontDispAmbient`. Observe que o objeto de fonte retornado por `COleControl::AmbientFont` devem ser liberados por uma chamada para o **IFontDisp::Release** função de membro.  
  
##  <a name="a-namepxfloata--pxfloat"></a><a name="px_float"></a>PX_Float  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **float**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `floatValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `floatDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `floatValue`, conforme apropriado. Se `floatDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxiunknowna--pxiunknown"></a><a name="px_iunknown"></a>PX_IUnknown  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade representada por um objeto com um **IUnknown**-interface derivada.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 *pUnk*  
 Referência a uma variável que contém a interface do objeto que representa o valor da propriedade.  
  
 `iid`  
 Uma ID de interface indicando qual interface do objeto de propriedade é usada pelo controle.  
  
 `pUnkDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por *pUnk*, conforme apropriado. Se `pUnkDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxlonga--pxlong"></a><a name="px_long"></a>PX_Long  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **longo**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `lValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `lDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `lValue`, conforme apropriado. Se `lDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxpicturea--pxpicture"></a><a name="px_picture"></a>PX_Picture  
 Chame essa função dentro do controle `DoPropExchange` função de membro para serializar ou inicializar uma propriedade de imagem do seu controle.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `pict`  
 Referência a um [CPictureHolder](../../mfc/reference/cpictureholder-class.md) objeto onde a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `pictDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `pict`, conforme apropriado. Se `pictDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxshorta--pxshort"></a><a name="px_short"></a>PX_Short  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **curto**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `sValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `sDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `sValue`, conforme apropriado. Se `sDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxulonga--pxulong"></a><a name="px_ulong"></a>PX_ULong  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo **ULONG**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 Nome da propriedade trocada.  
  
 `ulValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `ulDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `ulValue`, conforme apropriado. Se `ulDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxushorta--pxushort"></a><a name="px_ushort"></a>PX_UShort  
 Chame essa função dentro do controle `DoPropExchange` a função de membro para serializar ou inicializar uma propriedade do tipo `unsigned` **curto**.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 Nome da propriedade trocada.  
  
 *usValue*  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 *usDefault*  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por *usValue*, conforme apropriado. Se *usDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxstringa--pxstring"></a><a name="px_string"></a>PXstring  
 Chame essa função dentro do controle **DoPropExchange** a função de membro para serializar ou inicializar uma propriedade de cadeia de caracteres.  
  
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
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `strValue`  
 Referência à variável em que a propriedade é armazenada (normalmente uma variável de membro da sua classe).  
  
 `strDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado para a variável referenciada por `strValue`, conforme apropriado. Se `strDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, o processo de serialização do controle falhar.  
  
##  <a name="a-namepxvbxfontconverta--pxvbxfontconvert"></a><a name="px_vbxfontconvert"></a>PX_VBXFontConvert  
 Chame essa função dentro do controle `DoPropExchange` função de membro para inicializar uma propriedade de fonte, convertendo as propriedades relacionadas a fonte de um controle VBX.  
  
```  
 
BOOL  
PX_VBXFontConvert(
    CPropExchange* 
pPX  ,  
    CFontHolder& font);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pPX`  
 Ponteiro para o [CPropExchange](../../mfc/reference/cpropexchange-class.md) objeto (normalmente passado como um parâmetro para `DoPropExchange`).  
  
 `font`  
 A propriedade fonte do controle OLE que contém as propriedades de fonte relacionadas do VBX convertidas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser usada apenas por um controle OLE que foi projetado como uma substituição direta para um controle VBX. Quando o ambiente de desenvolvimento do Visual Basic converte um formulário que contém um controle VBX para usar o controle OLE de substituição correspondente, ele chamará o controle **IDataObject::SetData** função, passando um conjunto de propriedades que contém dados de propriedade do controle VBX. Essa operação, por sua vez, faz com que o controle `DoPropExchange` função a ser invocada. `DoPropExchange`pode chamar `PX_VBXFontConvert` para converter as propriedades relacionadas a fonte do controle VBX (por exemplo, "FontName," "FontSize", e assim por diante) nos componentes de propriedade do controle OLE correspondentes.  
  
 `PX_VBXFontConvert`só deve ser chamado quando o controle está realmente sendo convertido de um aplicativo de formulário do VBX. Por exemplo:  
  
 [!code-cpp[NVC_MFCActiveXControl&#14;](../../mfc/codesnippet/cpp/persistence-of-ole-controls_1.cpp)]  
[!code-cpp[NVC_MFCActiveXControl&#15;](../../mfc/codesnippet/cpp/persistence-of-ole-controls_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

