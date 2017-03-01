---
title: Alocadores de classe e licenciamento | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.classes
dev_langs:
- C++
helpviewer_keywords:
- class factories, and licensing
ms.assetid: 53c4856a-4062-46db-9f69-dd4339f746b3
caps.latest.revision: 13
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
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: a8ef7ba19d2337e4e50f34d7cdd528024a1d90aa
ms.lasthandoff: 02/25/2017

---
# <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento
Para criar uma instância do seu controle OLE, um aplicativo de contêiner chama uma função de membro da fábrica de classe do controle. Como o controle é um objeto OLE real, a fábrica de classes é responsável pela criação de instâncias do seu controle. Cada classe de controle OLE deve ter uma fábrica de classes.  
  
 Outro recurso importante de controles OLE é sua capacidade de impor uma licença. ControlWizard permite incorporar licenciamento durante a criação do seu projeto de controle. Para obter mais informações sobre licenciamento de controle, consulte o artigo [controles ActiveX: licenciamento um controle ActiveX](../../mfc/mfc-activex-controls-licensing-an-activex-control.md).  
  
 A tabela a seguir lista as várias macros e funções usadas para declarar e implementar a fábrica de classes do controle e a licença do seu controle.  
  
### <a name="class-factories-and-licensing"></a>Alocadores de classe e licenciamento  
  
|||  
|-|-|  
|[DECLARE_OLECREATE_EX](#declare_olecreate_ex)|Declara a fábrica de classes para uma página de propriedade ou OLE.|  
|[IMPLEMENT_OLECREATE_EX](#implement_olecreate_ex)|Implementa o controle `GetClassID` de função e declara uma instância da fábrica de classe.|  
|[BEGIN_OLEFACTORY](#begin_olefactory)|Começa a declaração de qualquer função de licenciamento.|  
|[END_OLEFACTORY](#end_olefactory)|Termina a declaração de qualquer função de licenciamento.|  
|[AfxVerifyLicFile](#afxverifylicfile)|Verifica se um controle é licenciado para uso em um computador específico.|  
  
##  <a name="a-namedeclareolecreateexa--declareolecreateex"></a><a name="declare_olecreate_ex"></a>DECLARE_OLECREATE_EX  
 Declara uma fábrica de classes e a `GetClassID` função membro da sua classe de controle.  
  
```   
DECLARE_OLECREATE_EX(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle.  
  
### <a name="remarks"></a>Comentários  
 Use essa macro no arquivo de cabeçalho de classe de controle para um controle que não tem suporte para licenciamento.  
  
 Observe que essa macro tem a mesma finalidade como o exemplo de código a seguir:  
  
 [!code-cpp[NVC_MFCAxCtl&#14;](../../mfc/reference/codesnippet/cpp/class-factories-and-licensing_1.h)]  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameimplementolecreateexa--implementolecreateex"></a><a name="implement_olecreate_ex"></a>IMPLEMENT_OLECREATE_EX  
 Implementa a fábrica de classes do controle e o [GetClassID](../../mfc/reference/colecontrol-class.md#getclassid) função membro da sua classe de controle.  
  
```   
IMPLEMENT_OLECREATE_EX(
   class_name,   
    external_name,    
    l,   
    w1,   
    w2,   
    b1,   
    b2,   
    b3,   
    b4,   
    b5,   
    b6,   
    b7,
    b8)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de página de propriedade de controle.  
  
 *external_name*  
 O nome do objeto exposto a aplicativos.  
  
 *l, B1, w2, b1, b2, b3, b4, b5, b6, b7, M8*  
 Componentes da classe de **CLSID**. Para obter mais informações sobre esses parâmetros, consulte os comentários para [IMPLEMENT_OLECREATE](run-time-object-model-services.md#implement_olecreate).  
  
### <a name="remarks"></a>Comentários  
 Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que usa o `DECLARE_OLECREATE_EX` macro ou `BEGIN_OLEFACTORY` e `END_OLEFACTORY` macros. O nome externo é o identificador do controle OLE que é exposto a outros aplicativos. Contêineres de usam esse nome para solicitar um objeto dessa classe de controle.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-namebeginolefactorya--beginolefactory"></a><a name="begin_olefactory"></a>BEGIN_OLEFACTORY  
 Começa a declaração de sua fábrica de classe no arquivo de cabeçalho de sua classe de controle.  
  
``` 
BEGIN_OLEFACTORY(class_name)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 Especifica o nome da classe de controle cuja trata de fábrica de classes.  
  
### <a name="remarks"></a>Comentários  
 Declarações de funções de licenciamento de fábrica de classes devem começar imediatamente após `BEGIN_OLEFACTORY`.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameendolefactorya--endolefactory"></a><a name="end_olefactory"></a>END_OLEFACTORY  
 Termina a declaração da fábrica de classe do controle.  
  
```  
END_OLEFACTORY(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle cuja trata de fábrica de classes.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  
  
##  <a name="a-nameafxverifylicfilea--afxverifylicfile"></a><a name="afxverifylicfile"></a>AfxVerifyLicFile  
 Chame essa função para verificar que o arquivo de licença nomeada pelo `pszLicFileName` é válido para o controle OLE.  
  
```   
BOOL AFXAPI AfxVerifyLicFile(
    HINSTANCE  hInstance,  
    LPCTSTR  pszLicFileName,  
    LPOLESTR  pszLicFileContents,  
    UINT cch = -1); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 O identificador de instância da DLL associado ao controle licenciado.  
  
 `pszLicFileName`  
 Aponta para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo de licença.  
  
 `pszLicFileContents`  
 Aponta para uma sequência de bytes que deve corresponder a sequência encontrada no início do arquivo de licença.  
  
 `cch`  
 Número de caracteres em `pszLicFileContents`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o arquivo de licença existe e começa com a sequência de caracteres `pszLicFileContents`; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `cch` é â €"1, essa função usa:  
  
 [!code-cpp[NVC_MFC_Utilities&#36;](../../mfc/codesnippet/cpp/class-factories-and-licensing_2.cpp)]  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxctl.h  

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

