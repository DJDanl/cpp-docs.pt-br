---
title: Classe COleVariant | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleVariant
- AFXDISP/COleVariant
- AFXDISP/COleVariant::COleVariant
- AFXDISP/COleVariant::Attach
- AFXDISP/COleVariant::ChangeType
- AFXDISP/COleVariant::Clear
- AFXDISP/COleVariant::Detach
- AFXDISP/COleVariant::GetByteArrayFromVariantArray
- AFXDISP/COleVariant::SetString
dev_langs:
- C++
helpviewer_keywords:
- Automation, parameter types
- COleVariant class
- VARIANT data type
ms.assetid: e1b5cd4a-b066-4b9b-b48b-6215ed52d998
caps.latest.revision: 24
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 753566adc5fc8e48ad31da52c2bb3f04c9e21727
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="colevariant-class"></a>Classe COleVariant
Encapsula o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) tipo de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleVariant : public tagVARIANT  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleVariant::COleVariant](#colevariant)|Constrói um objeto `COleVariant`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleVariant::Attach](#attach)|Anexa uma **VARIANT** para um `COleVariant`.|  
|[COleVariant::ChangeType](#changetype)|Altera o tipo de variante desse `COleVariant` objeto.|  
|[COleVariant::Clear](#clear)|Limpa esse `COleVariant` objeto.|  
|[COleVariant::Detach](#detach)|Desanexa um **VARIANT** de um `COleVariant` e retorna o **VARIANT**.|  
|[COleVariant::GetByteArrayFromVariantArray](#getbytearrayfromvariantarray)|Recupera uma matriz de bytes de uma matriz de variant existente.|  
|[COleVariant::SetString](#setstring)|Define a cadeia de caracteres para um tipo específico, normalmente ANSI.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleVariant::operator LPCVARIANT](#operator_lpcvariant)|Converte um `COleVariant` valor em um `LPCVARIANT`.|  
|[COleVariant::operator LPVARIANT](#operator_lpvariant)|Converte um `COleVariant` do objeto em um `LPVARIANT`.|  
|[COleVariant::operator =](#operator_eq)|Copia uma `COleVariant` valor.|  
|[COleVariant::operator = =](#operator_eq_eq)|Compara dois `COleVariant` valores.|  
|[COleVariant::operator &lt; &lt;,&gt;&gt;](#operator_lt_lt__gt_gt)|Saídas um `COleVariant` valor `CArchive` ou `CDumpContext` e insere um `COleVariant` de objeto `CArchive`.|  
  
## <a name="remarks"></a>Comentários  
 Esse tipo de dados é usado na automação OLE. Especificamente, o [DISPPARAMS](http://msdn.microsoft.com/en-us/a16e5a21-766e-4287-b039-13429aa78f8b) estrutura contém um ponteiro para uma matriz de **VARIANT** estruturas. A **DISPPARAMS** estrutura é usada para passar parâmetros para [IDispatch:: Invoke](http://msdn.microsoft.com/en-us/964ade8e-9d8a-4d32-bd47-aa678912a54d).  
  
> [!NOTE]
>  Essa classe é derivada do **VARIANT** estrutura. Isso significa que você pode passar um `COleVariant` em um parâmetro que chama uma **VARIANT** e que os membros de dados de **VARIANT** estrutura são membros de dados acessível `COleVariant`.  
  
 Os dois relacionados classes MFC [COleCurrency](../../mfc/reference/colecurrency-class.md) e [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) encapsular os tipos de dados variant **moeda** ( `VT_CY`) e **data** ( `VT_DATE`). O `COleVariant` classe é usada extensivamente nas classes DAO; consulte essas classes para uso normal dessa classe, por exemplo [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 Para obter mais informações, consulte o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118), [moeda](http://msdn.microsoft.com/en-us/5e81273c-7289-45c7-93c0-32c1553f708e), [DISPPARAMS](http://msdn.microsoft.com/en-us/a16e5a21-766e-4287-b039-13429aa78f8b), e [IDispatch:: Invoke](http://msdn.microsoft.com/en-us/964ade8e-9d8a-4d32-bd47-aa678912a54d) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre o `COleVariant` classe e seu uso na automação OLE, consulte o artigo "Passando parâmetros na automação OLE" [automação](../../mfc/automation.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `tagVARIANT`  
  
 `COleVariant`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
  
##  <a name="attach"></a>COleVariant::Attach  
 Chame essa função para anexar a determinada [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) objeto atual `COleVariant` objeto.  
  
```  
void Attach(VARIANT& varSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Existente **VARIANT** o objeto a ser anexado à atual `COleVariant` objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função define o [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) de *varSrc* para `VT_EMPTY`.  
  
 Para obter mais informações, consulte o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) e [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="colevariant"></a>COleVariant::COleVariant  
 Constrói um objeto `COleVariant`.  
  
```  
COleVariant(); 
COleVariant(const VARIANT& varSrc); 
COleVariant(const COleVariant& varSrc); 
COleVariant(LPCVARIANT pSrc); 
COleVariant(LPCTSTR lpszSrc); 
COleVariant(LPCTSTR lpszSrc, VARTYPE vtSrc); 
COleVariant(CString& strSrc); 
COleVariant(BYTE nSrc); 
COleVariant(short nSrc, VARTYPE vtSrc = VT_I2); 
COleVariant(long lSrc,VARTYPE vtSrc = VT_I4); 
COleVariant(const COleCurrency& curSrc); 
COleVariant(float fltSrc); 
COleVariant(double dblSrc); 
COleVariant(const COleDateTime& timeSrc); 
COleVariant(const CByteArray& arrSrc); 
COleVariant(const CLongBinary& lbSrc); 
COleVariant(LPCITEMIDLIST pidl);
```  
  
### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Existente `COleVariant` ou **VARIANT** o objeto a ser copiado para o novo `COleVariant` objeto.  
  
 `pSrc`  
 Um ponteiro para um **VARIANT** que será copiado para o novo objeto `COleVariant` objeto.  
  
 `lpszSrc`  
 Uma cadeia de caracteres terminada em nulo sejam copiados para o novo `COleVariant` objeto.  
  
 `vtSrc`  
 O `VARTYPE` para o novo `COleVariant` objeto.  
  
 `strSrc`  
 A [CString](../../atl-mfc-shared/reference/cstringt-class.md) o objeto a ser copiado para o novo `COleVariant` objeto.  
  
 `nSrc`, `lSrc`  
 Um valor numérico a ser copiado no novo objeto `COleVariant`.  
  
 `vtSrc`  
 O `VARTYPE` para o novo `COleVariant` objeto.  
  
 `curSrc`  
 A [COleCurrency](../../mfc/reference/colecurrency-class.md) o objeto a ser copiado para o novo `COleVariant` objeto.  
  
 `fltSrc`, `dblSrc`  
 Um valor numérico a ser copiado no novo objeto `COleVariant`.  
  
 `timeSrc`  
 A [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) o objeto a ser copiado para o novo `COleVariant` objeto.  
  
 `arrSrc`  
 A [CByteArray](../../mfc/reference/cbytearray-class.md) o objeto a ser copiado para o novo `COleVariant` objeto.  
  
 `lbSrc`  
 A [CLongBinary](../../mfc/reference/clongbinary-class.md) o objeto a ser copiado para o novo `COleVariant` objeto.  
  
 `pidl`  
 Um ponteiro para um [ITEMIDLIST](http://msdn.microsoft.com/library/windows/desktop/bb773321) estrutura a ser copiado para o novo `COleVariant` objeto.  
  
### <a name="remarks"></a>Comentários  
 Todos esses construtores criam novos `COleVariant` objetos inicializados com o valor especificado. Segue uma breve descrição de cada um desses construtores.  
  
- **(COleVariant)** cria vazia `COleVariant` objeto, `VT_EMPTY`.  
  
- **COleVariant (** *varSrc* **)** copia existente **VARIANT** ou `COleVariant` objeto. O tipo de variante é mantido.  
  
- **COleVariant (** `pSrc` **)** copia existente **VARIANT** ou `COleVariant` objeto. O tipo de variante é mantido.  
  
- **COleVariant (** `lpszSrc` **)** copia uma cadeia de caracteres para o novo objeto, `VT_BSTR` (UNICODE).  
  
- **COleVariant (** `lpszSrc` **,** `vtSrc` **)** copia uma cadeia de caracteres para o novo objeto. O parâmetro `vtSrc` deve ser `VT_BSTR` (UNICODE) ou `VT_BSTRT` (ANSI).  
  
- **COleVariant (** `strSrc` **)** copia uma cadeia de caracteres para o novo objeto, **VT_BSTR** (UNICODE).  
  
- **COleVariant (** `nSrc` **)** copia um inteiro de 8 bits para o novo objeto, `VT_UI1`.  
  
- **COleVariant (** `nSrc` **,** `vtSrc` **)** copia um inteiro de 16 bits (ou valor booleano) para o novo objeto. O parâmetro `vtSrc` deve ser `VT_I2` ou `VT_BOOL`.  
  
- **COleVariant (** `lSrc` **,** `vtSrc` **)** copia um inteiro de 32 bits (ou `SCODE` valor) para o novo objeto. O parâmetro `vtSrc` deve ser `VT_I4`, `VT_ERROR`, ou `VT_BOOL`.  
  
- **COleVariant (** `curSrc` **)** cópias de uma **COleCurrency** valor no novo objeto `VT_CY`.  
  
- **COleVariant (** `fltSrc` **)** copia um valor de ponto flutuante de 32 bits para o novo objeto, `VT_R4`.  
  
- **COleVariant (** `dblSrc` **)** copia um valor de ponto flutuante de 64 bits para o novo objeto, `VT_R8`.  
  
- **COleVariant (** `timeSrc` **)** cópias de uma `COleDateTime` valor no novo objeto `VT_DATE`.  
  
- **COleVariant (** `arrSrc` **)** cópias de uma `CByteArray` o objeto para o novo objeto, `VT_EMPTY`.  
  
- **COleVariant (** `lbSrc` **)** cópias de uma `CLongBinary` o objeto para o novo objeto, `VT_EMPTY`.  
  
 Para obter mais informações sobre `SCODE`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="changetype"></a>COleVariant::ChangeType  
 Converte o tipo de valor variant neste `COleVariant` objeto.  
  
```  
void ChangeType(VARTYPE vartype, LPVARIANT pSrc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `vartype`  
 O [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) para este `COleVariant` objeto.  
  
 `pSrc`  
 Um ponteiro para o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) objeto a ser convertido. Se esse valor for **nulo**, esse `COleVariant` objeto é usado como a origem para a conversão.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118), [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4), e [VariantChangeType](http://msdn.microsoft.com/en-us/48a51e32-95d7-4eeb-8106-f5043ffa2fd1) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="clear"></a>COleVariant::Clear  
 Limpa o **VARIANT**.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Isso define o **VARTYPE** para este objeto `VT_EMPTY`. O `COleVariant` destruidor chama essa função.  
  
 Para obter mais informações, consulte o `VARIANT`, `VARTYPE`, e `VariantClear` entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="detach"></a>COleVariant::Detach  
 Desanexa subjacente [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) objeto neste `COleVariant` objeto.  
  
```  
VARIANT Detach();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função define o [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) para este `COleVariant` objeto `VT_EMPTY`.  
  
> [!NOTE]
>  Depois de chamar **desanexar**, é responsabilidade do chamador chame **VariantClear** em resultante **VARIANT** estrutura.  
  
 Para obter mais informações, consulte o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118), [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4), e [VariantClear](http://msdn.microsoft.com/en-us/28741d81-8404-4f85-95d3-5c209ec13835) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getbytearrayfromvariantarray"></a>COleVariant::GetByteArrayFromVariantArray  
 Recupera uma matriz de bytes de uma matriz de variant existente  
  
```  
void GetByteArrayFromVariantArray(CByteArray& bytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bytes`  
 Uma referência a um existente [CByteArray](../../mfc/reference/cbytearray-class.md) objeto.  
  
##  <a name="operator_lpcvariant"></a>COleVariant::operator LPCVARIANT  
 Esse operador de conversão retornará um `VARIANT` estrutura cujo valor é copiado neste `COleVariant` objeto.  
  
```  
operator LPCVARIANT() const; 
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="operator_lpvariant"></a>COleVariant::operator LPVARIANT  
 Chame esse operador de conversão para acessar subjacente `VARIANT` estrutura para isso `COleVariant` objeto.  
  
```  
operator LPVARIANT();
```   
  
### <a name="remarks"></a>Comentários  
  
> [!CAUTION]
>  Altere o valor na **VARIANT** estrutura acessada pelo ponteiro retornado por essa função alterará o valor desse `COleVariant` objeto.  
  
##  <a name="operator_eq"></a>COleVariant::operator =  
 Esses operadores de atribuição sobrecarregados copie o valor de origem para este `COleVariant` objeto.  
  
```  
const COleVariant& operator=(const VARIANT& varSrc); 
const COleVariant& operator=(LPCVARIANT pSrc); 
const COleVariant& operator=(const COleVariant& varSrc); 
const COleVariant& operator=(const LPCTSTR lpszSrc);
const COleVariant& operator=(const CString& strSrc); 
const COleVariant& operator=(BYTE nSrc); 
const COleVariant& operator=(short nSrc); 
const COleVariant& operator=(long lSrc); 
const COleVariant& operator=(const COleCurrency& curSrc); 
const COleVariant& operator=(float fltSrc); 
const COleVariant& operator=(double dblSrc); 
const COleVariant& operator=(const COleDateTime& dateSrc); 
const COleVariant& operator=(const CByteArray& arrSrc); 
const COleVariant& operator=(const CLongBinary& lbSrc);
```  
  
### <a name="remarks"></a>Comentários  
 Segue uma breve descrição de cada operador:  
  
- **operador = (** *varSrc***)** copia existente **VARIANT** ou `COleVariant` objeto para esse objeto.  
  
- **operador = (** `pSrc` **)** cópias de **VARIANT** objeto acessado pela `pSrc` para esse objeto.  
  
- **operador = (** `lpszSrc` **)** copia uma cadeia de caracteres terminada em nulo para esse objeto e define o **VARTYPE** para `VT_BSTR`.  
  
- **operador = (** `strSrc` **)** cópias de uma [CString](../../atl-mfc-shared/reference/cstringt-class.md) o objeto para esse objeto e define o **VARTYPE** para `VT_BSTR`.  
  
- **operador = (** `nSrc` **)** copia um valor inteiro de 8 ou 16 bits para esse objeto. Se `nSrc` é um valor de 8 bits, o **VARTYPE** isso é definido como `VT_UI1`. Se `nSrc` é um valor de 16 bits e o **VARTYPE** disso é `VT_BOOL`, ele é mantido; caso contrário, ele é definido como `VT_I2`.  
  
- **operador = (** `lSrc` **)** copia um valor inteiro de 32 bits para esse objeto. Se o **VARTYPE** disso é `VT_ERROR`, ele é mantido; caso contrário, ele é definido como `VT_I4`.  
  
- **operador = (** `curSrc` **)** cópias de uma [COleCurrency](../../mfc/reference/colecurrency-class.md) o objeto para esse objeto e define o **VARTYPE** para `VT_CY`.  
  
- **operador = (** `fltSrc` **)** copia um valor de ponto flutuante de 32 bits para esse objeto e define o **VARTYPE** para `VT_R4`.  
  
- **operador = (** `dblSrc` **)** copia um valor de ponto flutuante de 64 bits para esse objeto e define o **VARTYPE** para `VT_R8`.  
  
- **operador = (** `dateSrc` **)** cópias de uma [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) o objeto para esse objeto e define o **VARTYPE** para `VT_DATE`.  
  
- **operador = (** `arrSrc` **)** cópias de uma [CByteArray](../../mfc/reference/cbytearray-class.md) esse objeto `COleVariant` objeto.  
  
- **operador = (** `lbSrc` **)** cópias de uma [CLongBinary](../../mfc/reference/clongbinary-class.md) esse objeto `COleVariant` objeto.  
  
 Para obter mais informações, consulte o [VARIANT](http://msdn.microsoft.com/en-us/e305240e-9e11-4006-98cc-26f4932d2118) e [VARTYPE](http://msdn.microsoft.com/en-us/317b911b-1805-402d-a9cb-159546bc88b4) entradas na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="operator_eq_eq"></a>COleVariant::operator = =  
 Este operador compara dois valores de variável e retorna zero se eles forem iguais; Caso contrário, 0.  
  
```  
BOOL operator==(const VARIANT& varSrc) const; 
BOOL operator==(LPCVARIANT pSrc) const;
```  
  
##  <a name="operator_lt_lt__gt_gt"></a>COleVariant::operator &lt; &lt;,&gt;&gt;  
 Saídas um `COleVariant` valor `CArchive` ou **CdumpContext** e insere um `COleVariant` de objeto `CArchive`.  
  
```  
friend CDumpContext& AFXAPI operator<<(
    CDumpContext& dc,  
    OleVariant varSrc);
 
friend CArchive& AFXAPI operator<<(
    CArchive& ar,  
    COleVariant varSrc);
 
friend CArchive& AFXAPI operator>>(
    CArchive& ar,  
    COleVariant& varSrc);
```  
  
### <a name="remarks"></a>Comentários  
 O `COleVariant` inserção ( ** < \< **) operador dá suporte a diagnóstico despejar e armazenar um arquivo. A extração ( ** >> **) operador oferece suporte ao carregamento de um arquivo.  
  
##  <a name="setstring"></a>COleVariant::SetString  
 Define a cadeia de caracteres para um determinado tipo.  
  
```  
void SetString(LPCTSTR lpszSrc, VARTYPE vtSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszSrc`  
 Uma cadeia de caracteres terminada em nulo sejam copiados para o novo `COleVariant` objeto.  
  
 *VtSrc*  
 O **VARTYPE** para o novo `COleVariant` objeto.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro `vtSrc` deve ser `VT_BSTR` (UNICODE) ou `VT_BSTRT` (ANSI). `SetString`normalmente é usado para definir strings para ANSI, desde o padrão para o [COleVariant::COleVariant](#colevariant) construtor com uma cadeia de caracteres ou parâmetro de ponteiro de cadeia de caracteres e não **VARTYPE** é UNICODE.  
  
 Um conjunto de registros DAO em uma compilação de não-UNICODE espera cadeias de caracteres serão ANSI. Assim, para DAO funções que usam `COleVariant` objetos, se você não estiver criando um conjunto de registros do UNICODE, você deve usar o **COleVariant::COleVariant (** `lpszSrc` **,** `vtSrc` **)** formulário do construtor com `vtSrc` definida como `VT_BSTRT` (ANSI) ou use `SetString` com `vtSrc` definida como `VT_BSTRT` para tornar as cadeias de caracteres ANSI. Por exemplo, o `CDaoRecordset` funções [CDaoRecordset::Seek](../../mfc/reference/cdaorecordset-class.md#seek) e [CDaoRecordset::SetFieldValue](../../mfc/reference/cdaorecordset-class.md#setfieldvalue) usar `COleVariant` objetos como parâmetros. Esses objetos devem ser ANSI se o conjunto de registros DAO não é UNICODE.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




