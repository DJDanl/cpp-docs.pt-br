---
title: Classe COleDataObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDataObject
- AFXOLE/COleDataObject
- AFXOLE/COleDataObject::COleDataObject
- AFXOLE/COleDataObject::Attach
- AFXOLE/COleDataObject::AttachClipboard
- AFXOLE/COleDataObject::BeginEnumFormats
- AFXOLE/COleDataObject::Detach
- AFXOLE/COleDataObject::GetData
- AFXOLE/COleDataObject::GetFileData
- AFXOLE/COleDataObject::GetGlobalData
- AFXOLE/COleDataObject::GetNextFormat
- AFXOLE/COleDataObject::IsDataAvailable
- AFXOLE/COleDataObject::Release
dev_langs:
- C++
helpviewer_keywords:
- COleDataObject [MFC], COleDataObject
- COleDataObject [MFC], Attach
- COleDataObject [MFC], AttachClipboard
- COleDataObject [MFC], BeginEnumFormats
- COleDataObject [MFC], Detach
- COleDataObject [MFC], GetData
- COleDataObject [MFC], GetFileData
- COleDataObject [MFC], GetGlobalData
- COleDataObject [MFC], GetNextFormat
- COleDataObject [MFC], IsDataAvailable
- COleDataObject [MFC], Release
ms.assetid: d1cc84be-2e1c-4bb3-a8a0-565eb08aaa34
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e9cd159597440dfb55bbe8abe147623096cdf449
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="coledataobject-class"></a>Classe COleDataObject
Usado em transferências de dados para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar, ou de um item OLE inserido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDataObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDataObject::COleDataObject](#coledataobject)|Constrói um objeto `COleDataObject`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDataObject::Attach](#attach)|Anexa o objeto de dados OLE especificado para o `COleDataObject`.|  
|[COleDataObject::AttachClipboard](#attachclipboard)|Anexa o objeto de dados na área de transferência.|  
|[COleDataObject::BeginEnumFormats](#beginenumformats)|Prepara para um ou mais subsequentes `GetNextFormat` chamadas.|  
|[COleDataObject::Detach](#detach)|Desanexa associado `IDataObject` objeto.|  
|[COleDataObject::GetData](#getdata)|Copia os dados do objeto de dados OLE anexado em um formato especificado.|  
|[COleDataObject::GetFileData](#getfiledata)|Copia os dados do objeto de dados OLE anexado em uma `CFile` ponteiro no formato especificado.|  
|[COleDataObject::GetGlobalData](#getglobaldata)|Copia os dados do objeto de dados OLE anexado em uma `HGLOBAL` no formato especificado.|  
|[COleDataObject::GetNextFormat](#getnextformat)|Retorna o seguinte formato de dados disponível.|  
|[COleDataObject::IsDataAvailable](#isdataavailable)|Verifica se os dados estão disponíveis em um formato especificado.|  
|[COleDataObject::Release](#release)|Desliga e libera associado `IDataObject` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `COleDataObject` não tem uma classe base.  
  
 Esses tipos de transferências de dados incluem uma origem e um destino. A fonte de dados é implementada como um objeto do [COleDataSource](../../mfc/reference/coledatasource-class.md) classe. Sempre que um aplicativo de destino tem dados descartados nele ou será solicitado a executar uma operação de colagem da área de transferência, um objeto do `COleDataObject` classe deve ser criada.  
  
 Essa classe permite que você determine se os dados se encontram em um formato especificado. Você pode também enumerar os formatos de dados disponíveis ou verificar se um determinado formato está disponível e, em seguida, recuperar os dados no formato preferencial. Recuperação de objetos pode ser feita de várias maneiras diferentes, incluindo o uso de um [CFile](../../mfc/reference/cfile-class.md), uma `HGLOBAL`, ou um **STGMEDIUM** estrutura.  
  
 Para obter mais informações, consulte o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura no SDK do Windows.  
  
 Para obter mais informações sobre como usar objetos de dados em seu aplicativo, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `COleDataObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="attach"></a>  COleDataObject::Attach  
 Chamar essa função para associar o `COleDataObject` objeto com um objeto de dados OLE.  
  
```  
void Attach(
    LPDATAOBJECT lpDataObject,  
    BOOL bAutoRelease = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDataObject*  
 Aponta para um objeto de dados OLE.  
  
 `bAutoRelease`  
 **TRUE** se o objeto de dados OLE deve ser liberados quando a `COleDataObject` objeto é destruído; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) no SDK do Windows.  
  
##  <a name="attachclipboard"></a>  COleDataObject::AttachClipboard  
 Chamar essa função para anexar o objeto de dados que está atualmente na área de transferência para o `COleDataObject` objeto.  
  
```  
BOOL AttachClipboard();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Chamar essa função bloqueia a área de transferência até que esse objeto de dados seja liberado. O objeto de dados foi lançado no destruidor para o `COleDataObject`. Para obter mais informações, consulte [OpenClipboard](http://msdn.microsoft.com/library/windows/desktop/ms649048) e [CloseClipboard](http://msdn.microsoft.com/library/windows/desktop/ms649035) na documentação do Win32.  
  
##  <a name="beginenumformats"></a>  COleDataObject::BeginEnumFormats  
 Chamar essa função para preparar para chamadas subsequentes para `GetNextFormat` para recuperar uma lista de formatos de dados do item.  
  
```  
void BeginEnumFormats();
```  
  
### <a name="remarks"></a>Comentários  
 Após uma chamada para `BeginEnumFormats`, a posição do primeiro formato suportada por este objeto de dados é armazenada. As chamadas sucessivas para `GetNextFormat` vai enumerar a lista de formatos disponíveis no objeto de dados.  
  
 Para verificar a disponibilidade dos dados em um determinado formato, use [COleDataObject::IsDataAvailable](#isdataavailable).  
  
 Para obter mais informações, consulte [IDataObject::EnumFormatEtc](http://msdn.microsoft.com/library/windows/desktop/ms683979) no SDK do Windows.  
  
##  <a name="coledataobject"></a>  COleDataObject::COleDataObject  
 Constrói um objeto `COleDataObject`.  
  
```  
COleDataObject();
```  
  
### <a name="remarks"></a>Comentários  
 Uma chamada para [COleDataObject::Attach](#attach) ou [COleDataObject::AttachClipboard](#attachclipboard) devem ser feitas antes de chamar outros `COleDataObject` funções.  
  
> [!NOTE]
>  Como um dos parâmetros para os manipuladores de arrastar e soltar é um ponteiro para um `COleDataObject`, não é necessário chamar o construtor para dar suporte a arrastar e soltar.  
  
##  <a name="detach"></a>  COleDataObject::Detach  
 Chamar essa função para desanexar o `COleDataObject` objeto a partir de seu objeto associado de dados OLE sem liberar o objeto de dados.  
  
```  
LPDATAOBJECT Detach();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto de dados OLE que foi desanexado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdata"></a>  COleDataObject::GetData  
 Chame essa função para recuperar dados do item no formato especificado.  
  
```  
BOOL GetData(
    CLIPFORMAT cfFormat,  
    LPSTGMEDIUM lpStgMedium,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato no qual os dados estão a ser retornado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpStgMedium`  
 Aponta para um [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura que receberá os dados.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados estão a ser retornado. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato de área de transferência especificado pelo `cfFormat`. Se for **nulo**, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431), [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no SDK do Windows.  
  
##  <a name="getfiledata"></a>  COleDataObject::GetFileData  
 Chamar essa função para criar um `CFile` ou `CFile`-objeto derivado e para recuperar dados no formato especificado em um `CFile` ponteiro.  
  
```  
CFile* GetFileData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato no qual os dados estão a ser retornado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados estão a ser retornado. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato de área de transferência especificado pelo `cfFormat`. Se for **nulo**, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o novo `CFile` ou `CFile`-objeto derivada que contém os dados se for bem-sucedida; caso contrário **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Dependendo da mídia em que os dados são armazenados no, o tipo real apontado pelo valor de retorno pode ser `CFile`, `CSharedFile`, ou `COleStreamFile`.  
  
> [!NOTE]
>  O `CFile` objeto acessado pelo valor de retorno dessa função é pertence ao chamador. É responsabilidade do chamador **excluir** o `CFile` objeto, assim, fechar o arquivo.  
  
 Para obter mais informações, consulte [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no SDK do Windows.  
  
##  <a name="getglobaldata"></a>  COleDataObject::GetGlobalData  
 Chamar essa função para alocar um bloco de memória global e para recuperar dados no formato especificado em um `HGLOBAL`.  
  
```  
HGLOBAL GetGlobalData(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato no qual os dados estão a ser retornado. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato no qual os dados estão a ser retornado. Forneça um valor para esse parâmetro se você deseja especificar informações de formato adicionais além do formato de área de transferência especificado pelo `cfFormat`. Se for **nulo**, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador do bloco de memória global que contém os dados se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no SDK do Windows.  
  
##  <a name="getnextformat"></a>  COleDataObject::GetNextFormat  
 Chame essa função repetidamente para obter todos os formatos disponíveis para recuperar dados do item.  
  
```  
BOOL GetNextFormat(LPFORMATETC lpFormatEtc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para o [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que recebe as informações de formato quando a chamada de função retorna.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se outro formato está disponível. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Após uma chamada para [COleDataObject::BeginEnumFormats](#beginenumformats), a posição do primeiro formato suportada por este objeto de dados é armazenada. As chamadas sucessivas para `GetNextFormat` vai enumerar a lista de formatos disponíveis no objeto de dados. Use essas funções para listar os formatos disponíveis.  
  
 Para verificar a disponibilidade de um determinado formato, chame [COleDataObject::IsDataAvailable](#isdataavailable).  
  
 Para obter mais informações, consulte [IEnumXXXX::Next](https://msdn.microsoft.com/library/ms695273.aspx) no SDK do Windows.  
  
##  <a name="isdataavailable"></a>  COleDataObject::IsDataAvailable  
 Chame essa função para determinar se um determinado formato está disponível para recuperar dados de item OLE.  
  
```  
BOOL IsDataAvailable(
    CLIPFORMAT cfFormat,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cfFormat`  
 O formato de dados de área de transferência a ser usado na estrutura apontada pelo `lpFormatEtc`. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado pelo Windows nativo [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) função.  
  
 `lpFormatEtc`  
 Aponta para um [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura que descreve o formato desejado. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato de área de transferência especificado pelo `cfFormat`. Se for **nulo**, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se os dados estão disponíveis no formato especificado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil antes de chamar `GetData`, `GetFileData`, ou `GetGlobalData`.  
  
 Para obter mais informações, consulte [IDataObject::QueryGetData](http://msdn.microsoft.com/library/windows/desktop/ms680637) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no SDK do Windows.  
  
 Para obter mais informações, consulte [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::QueryAcceptData](../../mfc/reference/cricheditview-class.md#queryacceptdata).  
  
##  <a name="release"></a>  COleDataObject::Release  
 Chamar essa função para liberar a propriedade do [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) objeto que foi previamente associado a `COleDataObject` objeto.  
  
```  
void Release();
```  
  
### <a name="remarks"></a>Comentários  
 O `IDataObject` foi associado a `COleDataObject` chamando **Attach** ou `AttachClipboard` explicitamente ou pela estrutura. Se o `bAutoRelease` parâmetro **Attach** é **FALSE**, o `IDataObject` objeto não será liberado. Nesse caso, o chamador é responsável pela liberação de `IDataObject` chamando [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms682317).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDataSource](../../mfc/reference/coledatasource-class.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
