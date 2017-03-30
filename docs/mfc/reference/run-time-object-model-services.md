---
title: "Serviços do modelo de objeto de tempo de execução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- run-time object model services macros
ms.assetid: 4a3e79df-2ee3-43a4-8193-20298828de85
caps.latest.revision: 15
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
ms.sourcegitcommit: 3d045736f9a54d344c67e3f7408198e65a0bc95f
ms.openlocfilehash: 0cc29b21aa2279e51ba666d7447d913c4cc777d4
ms.lasthandoff: 03/29/2017

---
# <a name="run-time-object-model-services"></a>Serviços do modelo de objeto de tempo de execução
As classes [CObject](../../mfc/reference/cobject-class.md) e [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) encapsular vários serviços de objeto, incluindo o acesso a informações de classe de tempo de execução, a serialização e a criação de objeto dinâmico. Todas as classes derivadas de `CObject` herdam essa funcionalidade.  
  
 Acesso a informações de classe de tempo de execução permite que você determinar as informações sobre uma classe de objeto em tempo de execução. A capacidade de determinar a classe de um objeto em tempo de execução é útil quando você precisar extraverificação de tipo de argumentos de função e você deve escrever o código de finalidade especial com base na classe de um objeto. Não há suporte para informações de classe de tempo de execução diretamente, a linguagem C++.  
  
 A serialização é o processo de escrever ou ler o conteúdo de um objeto para ou de um arquivo. Você pode usar a serialização para armazenar o conteúdo de um objeto mesmo depois que o aplicativo será encerrado. O objeto, em seguida, pode ser lido do arquivo quando o aplicativo é reiniciado. Esses objetos de dados são considerados "persistente".  
  
 Criação de objeto dinâmico permite que você crie um objeto de uma classe especificada em tempo de execução. Por exemplo, documento, exibição e objetos de quadro devem oferecer suporte a criação dinâmica porque a estrutura precisa criá-los dinamicamente.  
  
 A tabela a seguir lista as macros MFC que oferecem suporte à criação dinâmica, serialização e informações de classe de tempo de execução.  
  
 Para obter mais informações sobre esses serviços de objeto de tempo de execução e a serialização, consulte o artigo [classe CObject: acessar informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).  
  
### <a name="run-time-object-model-services-macros"></a>Macros de serviços do modelo de objeto de tempo de execução  
  
|||  
|-|-|  
|[DECLARE_DYNAMIC](#declare_dynamic)|Permite o acesso a informações de classe de tempo de execução (deve ser usado na declaração da classe).|  
|[DECLARE_DYNCREATE](#declare_dyncreate)|Permite a criação dinâmica e acesso a informações de classe de tempo de execução (deve ser usado na declaração da classe).|  
|[DECLARE_SERIAL](#declare_serial)|Permite o acesso às informações de classe de tempo de execução (deve ser usado na declaração da classe) e serialização.|  
|[IMPLEMENT_DYNAMIC](#implement_dynamic)|Permite o acesso a informações de classe de tempo de execução (deve ser usado na implementação de classe).|  
|[IMPLEMENT_DYNCREATE](#implement_dyncreate)|Permite a criação dinâmica e acesso a informações de tempo de execução (deve ser usado na implementação de classe).|  
|[IMPLEMENT_SERIAL](#implement_serial)|Permite acesso a informações de classe de tempo de execução (deve ser usado na implementação de classe) e serialização.|  
|[RUNTIME_CLASS](#runtime_class)|Retorna o `CRuntimeClass` estrutura que corresponde à classe nomeada.|  


 OLE frequentemente exige a criação dinâmica de objetos em tempo de execução. Por exemplo, um aplicativo de servidor OLE deve ser capaz de criar itens OLE dinamicamente em resposta a uma solicitação de um cliente. Da mesma forma, um servidor de automação deve ser capaz de criar itens em resposta a solicitações de clientes de automação.  
  
 A biblioteca Microsoft Foundation Class fornece duas macros específicas para OLE.  
  
### <a name="dynamic-creation-of-ole-objects"></a>Criação dinâmica de objetos OLE  
  
|||  
|-|-|  
|[DECLARE_OLECREATE](#declare_olecreate)|Permite que os objetos a serem criados por meio de automação OLE.|  
|[IMPLEMENT_OLECREATE](#implement_olecreate)|Permite que os objetos a serem criados pelo sistema OLE.|  
  
##  <a name="declare_dynamic"></a>DECLARE_DYNAMIC  
 Adiciona a capacidade de acessar as informações de tempo de execução de uma classe de objeto ao derivar uma classe de `CObject`.  
  
```
DECLARE_DYNAMIC(class_name) 
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
### <a name="remarks"></a>Comentários  
 Adicionar o `DECLARE_DYNAMIC` macro para o módulo de cabeçalho (. h) para a classe incluem depois que o módulo em todos os módulos. cpp que precisam de acesso para objetos desta classe.  
  
 Se você usar o **DECLARE**_ **dinâmico** e `IMPLEMENT_DYNAMIC` macros conforme descrito, você pode usar o `RUNTIME_CLASS` macro e `CObject::IsKindOf` função para determinar a classe dos objetos de tempo de execução.  
  
 Se `DECLARE_DYNAMIC` está incluído na declaração da classe, em seguida, `IMPLEMENT_DYNAMIC` devem ser incluídos na implementação da classe.  
  
 Para obter mais informações sobre o `DECLARE_DYNAMIC` macro, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [IMPLEMENT_DYNAMIC](#implement_dynamic).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 

##  <a name="declare_dyncreate"></a>DECLARE_DYNCREATE  
 Permite que objetos de `CObject`-classes derivadas para ser criado dinamicamente em tempo de execução.  
  
```
DECLARE_DYNCREATE(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa essa capacidade para criar novos objetos dinamicamente. Por exemplo, o novo modo de exibição criado quando você abre um novo documento. Documento, exibição e classes de quadro devem dar suporte a criação dinâmica porque a estrutura precisa criá-los dinamicamente.  
  
 Adicionar o `DECLARE_DYNCREATE` macro no módulo. h para a classe incluem depois que o módulo em todos os módulos. cpp que precisam de acesso para objetos desta classe.  
  
 Se `DECLARE_DYNCREATE` está incluído na declaração da classe, em seguida, `IMPLEMENT_DYNCREATE` devem ser incluídos na implementação da classe.  
  
 Para obter mais informações sobre o `DECLARE_DYNCREATE` macro, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
> [!NOTE]
>  O `DECLARE_DYNCREATE` macro inclui toda a funcionalidade de `DECLARE_DYNAMIC`.  
  
### <a name="example"></a>Exemplo  
 Consulte o exemplo para [IMPLEMENT_DYNCREATE](#implement_dyncreate).  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 

##  <a name="declare_serial"></a>DECLARE_SERIAL  
 Gera o código de cabeçalho do C++ necessário para um `CObject`-derivada da classe que pode ser serializado.  
  
```
DECLARE_SERIAL(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
### <a name="remarks"></a>Comentários  
 A serialização é o processo de gravar ou ler o conteúdo de um objeto para e de um arquivo.  
  
 Use o `DECLARE_SERIAL` macro em um módulo. h e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam de acesso para objetos desta classe.  
  
 Se `DECLARE_SERIAL` está incluído na declaração da classe, em seguida, `IMPLEMENT_SERIAL` devem ser incluídos na implementação da classe.  
  
 O `DECLARE_SERIAL` macro inclui toda a funcionalidade de `DECLARE_DYNAMIC` e `DECLARE_DYNCREATE`.  
  
 Você pode usar o **AFX_API** macro para exportar automaticamente o `CArchive` operador de extração para classes que usam o `DECLARE_SERIAL` e `IMPLEMENT_SERIAL` macros. Suporte as declarações de classe (localizadas no arquivo. h) com o código a seguir:  
  
 [!code-cpp[NVC_MFCCObjectSample n º 20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]  
  
 Para obter mais informações sobre o `DECLARE_SERIAL` macro, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCObjectSample #21](../../mfc/codesnippet/cpp/run-time-object-model-services_2.h)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 

##  <a name="implement_dynamic"></a>IMPLEMENT_DYNAMIC  
 Gera o código C++ necessário para um dinâmico `CObject`-a classe derivada com acesso de tempo de execução para o nome de classe e a posição dentro da hierarquia.  
  
```
IMPLEMENT_DYNAMIC(class_name, base_class_name)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
 `base_class_name`  
 O nome da classe base.  
  
### <a name="remarks"></a>Comentários  
 Use o `IMPLEMENT_DYNAMIC` macro em um módulo. cpp e vincule o objeto resultante de código apenas uma vez.  
  
 Para obter mais informações, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCObjectSample n º 2](../../mfc/codesnippet/cpp/run-time-object-model-services_3.h)]  
  
 [!code-cpp[NVC_MFCCObjectSample n º 3](../../mfc/codesnippet/cpp/run-time-object-model-services_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 

##  <a name="implement_dyncreate"></a>IMPLEMENT_DYNCREATE  
 Permite que objetos de `CObject`-classes derivadas para ser criada dinamicamente na execução de tempo quando usado com o `DECLARE_DYNCREATE` macro.  
  
```
IMPLEMENT_DYNCREATE(class_name, base_class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
 `base_class_name`  
 O nome real da classe base.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa essa capacidade para criar novos objetos dinamicamente, por exemplo, quando ele lê um objeto do disco durante a serialização. Adicionar o `IMPLEMENT_DYNCREATE` macro no arquivo de implementação da classe. Para obter mais informações, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
 Se você usar o `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE` macros, você pode usar o `RUNTIME_CLASS` macro e `CObject::IsKindOf` a função de membro para determinar a classe dos objetos de tempo de execução.  
  
 Se `DECLARE_DYNCREATE` está incluído na declaração da classe, em seguida, `IMPLEMENT_DYNCREATE` devem ser incluídos na implementação da classe.  
  
 Observe que essa definição de macro chamará o construtor padrão para a sua classe. Se um construtor não trivial explicitamente é implementado pela classe, ele deve implementar explicitamente construtor padrão. O construtor padrão pode ser adicionado para a classe **privada** ou **protegido** seções de membro para impedir que ele está sendo chamado de fora a implementação da classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCObjectSample #22](../../mfc/codesnippet/cpp/run-time-object-model-services_5.h)]  
  
 [!code-cpp[NVC_MFCCObjectSample #23](../../mfc/codesnippet/cpp/run-time-object-model-services_6.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 

##  <a name="implement_serial"></a>IMPLEMENT_SERIAL  
 Gera o código C++ necessário para um dinâmico `CObject`-a classe derivada com acesso de tempo de execução para o nome de classe e a posição dentro da hierarquia.  
  
```
IMPLEMENT_SERIAL(class_name, base_class_name, wSchema)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
 `base_class_name`  
 O nome da classe base.  
  
 *wSchema*  
 Um **UINT** "número de versão" que será codificado no arquivo para habilitar um programa desserializar identificar e manipular dados criados por versões de programa anteriormente. O número de esquema de classe não deve ser -1.  
  
### <a name="remarks"></a>Comentários  
 Use o `IMPLEMENT_SERIAL` macro em um módulo. cpp; em seguida, vincule o código resultante do objeto apenas uma vez.  
  
 Você pode usar o **AFX_API** macro para exportar automaticamente o `CArchive` operador de extração para classes que usam o `DECLARE_SERIAL` e `IMPLEMENT_SERIAL` macros. Suporte as declarações de classe (localizadas no arquivo. h) com o código a seguir:  
  
 [!code-cpp[NVC_MFCCObjectSample n º 20](../../mfc/codesnippet/cpp/run-time-object-model-services_1.h)]  
  
 Para obter mais informações, consulte o [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCCObjectSample #24](../../mfc/codesnippet/cpp/run-time-object-model-services_7.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 

##  <a name="runtime_class"></a>RUNTIME_CLASS  
 Obtém a estrutura de classe de tempo de execução do nome de uma classe do C++.  
  
```
RUNTIME_CLASS(class_name)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe (não entre aspas).  
  
### <a name="remarks"></a>Comentários  
 `RUNTIME_CLASS`Retorna um ponteiro para um [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura para a classe especificada por *class_name*. Somente `CObject`-declarados com classes derivadas `DECLARE_DYNAMIC`, `DECLARE_DYNCREATE`, ou `DECLARE_SERIAL` retornarão ponteiros para um `CRuntimeClass` estrutura.  
  
 Para obter mais informações, consulte [tópicos de classe de CObject](../../mfc/using-cobject.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFCCObjectSample](../../mfc/codesnippet/cpp/run-time-object-model-services_8.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX 
   
##  <a name="declare_olecreate"></a>DECLARE_OLECREATE  
 Permite que objetos de `CCmdTarget`-classes derivadas para ser criada por meio de automação OLE.  
  
```
DECLARE_OLECREATE(class_name) 
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
### <a name="remarks"></a>Comentários  
 Esta macro permite que outros aplicativos habilitados para OLE criar objetos desse tipo.  
  
 Adicionar o `DECLARE_OLECREATE` macro no módulo. h para a classe e, em seguida, inclua esse módulo em todos os módulos. cpp que precisam de acesso para objetos desta classe.  
  
 Se `DECLARE_OLECREATE` está incluído na declaração da classe, em seguida, `IMPLEMENT_OLECREATE` devem ser incluídos na implementação da classe. Uma declaração de classe usando `DECLARE_OLECREATE` também deve usar `DECLARE_DYNCREATE` ou `DECLARE_SERIAL`.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h  

##  <a name="implement_olecreate"></a>IMPLEMENT_OLECREATE  
 Ou esta macro ou [IMPLEMENT_OLECREATE_FLAGS](http://msdn.microsoft.com/library/d1589f6a-5a69-4742-b07c-4c621cfd040d) devem aparecer no arquivo de implementação para qualquer classe que usa `DECLARE_OLECREATE`.  
  
```
IMPLEMENT_OLECREATE(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)  
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome real da classe.  
  
 *external_name*  
 O nome do objeto exposto a outros aplicativos (entre aspas).  
  
 *l*, *w1*, *w2*, *b1*, *b2*, *b3*, *b4*, *b5*, *b6*, *b7*, *b8*  
 Componentes da classe de **CLSID**.  
  
### <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  Se você usar `IMPLEMENT_OLECREATE`, por padrão, você oferece suporte a apenas o modelo de threading único. Se você usar `IMPLEMENT_OLECREATE_FLAGS`, você pode especificar qual modelo de threading dá suporte ao seu objeto usando o `nFlags` parâmetro.  
  
 O nome externo é o identificador exposto a outros aplicativos. Aplicativos clientes usam o nome externo para solicitar um objeto dessa classe de um servidor de automação.  
  
 A ID de classe OLE é um identificador exclusivo de 128 bits para o objeto. Ele consiste em uma **longo**, dois **WORD**s e oito **bytes**s, conforme representado por *l*, *w1*, *w2*, e *b1* por meio de *b8* na descrição de sintaxe. Os assistentes de Assistente de aplicativo e o código crie IDs exclusivas de classe OLE para você conforme necessário.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho**: afxdisp.h 

## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

