---
title: Classe CSettingsStoreSP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSettingsStoreSP
- AFXSETTINGSSTORE/CSettingsStoreSP
- AFXSETTINGSSTORE/CSettingsStoreSP::CSettingsStoreSP
- AFXSETTINGSSTORE/CSettingsStoreSP::Create
- AFXSETTINGSSTORE/CSettingsStoreSP::SetRuntimeClass
dev_langs:
- C++
helpviewer_keywords:
- CSettingsStoreSP [MFC], CSettingsStoreSP
- CSettingsStoreSP [MFC], Create
- CSettingsStoreSP [MFC], SetRuntimeClass
ms.assetid: bcd37f40-cfd4-4d17-a5ce-3bfabe995dcc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1852f4e280fa49a2436c421d4669e9d735d66c3b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33376034"
---
# <a name="csettingsstoresp-class"></a>Classe CSettingsStoreSP
O `CSettingsStoreSP` classe é uma classe auxiliar que você pode usar para criar instâncias de [CSettingsStore classe](../../mfc/reference/csettingsstore-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSettingsStoreSP  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSettingsStoreSP::CSettingsStoreSP](#csettingsstoresp)|Constrói um objeto `CSettingsStoreSP`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSettingsStoreSP::Create](#create)|Cria uma instância de uma classe derivada de `CSettingsStore`.|  
|[CSettingsStoreSP::SetRuntimeClass](#setruntimeclass)|Define a classe de tempo de execução. O `Create` método usa a classe de tempo de execução para determinar qual classe de objetos para criar.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|`m_dwUserData`|Dados de usuário personalizada que são armazenados no `CSettingsStoreSP` objeto. Forneça esses dados no construtor do `CSettingsStoreSP` objeto.|  
|`m_pRegistry`|O `CSettingsStore`-derivados do objeto que o `Create` método cria.|  
  
## <a name="remarks"></a>Comentários  
 Você pode usar o `CSettingsStoreSP` classe para redirecionar todas as operações de registro do MFC para outros locais, como um arquivo XML ou um banco de dados. Para fazer isso, execute estas etapas:  
  
1.  Criar uma classe (como `CMyStore`) e derivá-la de `CSettingsStore`.  
  
2.  Use [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate) e [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate) macros com personalizados `CSettingsStore` classe para habilitar a criação dinâmica.  
  
3.  Substituir as funções virtuais e implementar o `Read` e `Write` funções em sua classe personalizada. Implemente qualquer outra funcionalidade para ler e gravar dados para o local desejado.  
  
4.  No seu aplicativo, chame `CSettingsStoreSP::SetRuntimeClass` e passe um ponteiro para o [CRuntimeClass estrutura](../../mfc/reference/cruntimeclass-structure.md) obtidas da sua classe.  
  
 Sempre que a estrutura geralmente acessaria o registro, ele agora dinamicamente uma instância de sua classe personalizada e usá-lo para ler ou gravar dados.  
  
 `CSettingsStoreSP::SetRuntimeClass` usa uma variável estática global. Portanto, apenas um repositório personalizado está disponível por vez.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxsettingsstore.h  
  
##  <a name="create"></a>  CSettingsStoreSP::Create  
 Cria uma nova instância de um objeto que é derivado de [CSettingsStore classe](../../mfc/reference/csettingsstore-class.md).  
  
```  
CSettingsStore& CSettingsStoreSP Create(
    BOOL bAdmin,  
    BOOL bReadOnly);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAdmin`  
 Um parâmetro booliano que determina se um `CSettingsStore` objeto é criado no modo de administrador.  
  
 [in] `bReadOnly`  
 Um parâmetro booliano que determina se um `CSettingsStore` objeto é criado para acesso somente leitura.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a recém-criado `CSettingsStore` objeto.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o método [CSettingsStoreSP::SetRuntimeClass](#setruntimeclass) para determinar que tipo de objeto `CSettingsStoreSP::Create` criará. Por padrão, esse método cria um `CSettingsStore` objeto.  
  
 Se você criar um `CSettingsStore` objeto no modo de administrador, o local padrão para todo o acesso de registro HKEY_LOCAL_MACHINE. Caso contrário, o local padrão para todo o acesso de registro é HKEY_CURRENT_USER.  
  
 Se `bAdmin` é `TRUE`, o aplicativo deve ter direitos de administração. Caso contrário, ele falhará ao tentar acessar o registro.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método o `CSettingsStoreSP` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#33](../../mfc/reference/codesnippet/cpp/csettingsstoresp-class_1.cpp)]  
  
##  <a name="csettingsstoresp"></a>  CSettingsStoreSP::CSettingsStoreSP  
 Constrói um [CSettingsStoreSP classe](../../mfc/reference/csettingsstoresp-class.md) objeto.  
  
```  
CSettingsStoreSP::CSettingsStoreSP(DWORD dwUserData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwUserData`  
 Dados definidos pelo usuário que o `CSettingsStoreSP` repositórios do objeto.  
  
### <a name="remarks"></a>Comentários  
 O `CSettingsStoreSP` objeto armazena os dados de `dwUserData` na variável de membro protegido `m_dwUserData`.  
  
##  <a name="setruntimeclass"></a>  CSettingsStoreSP::SetRuntimeClass  
 Define a classe de tempo de execução. O método [CSettingsStoreSP::Create](#create) usa a classe de tempo de execução para determinar que tipo de objeto a ser criado.  
  
```  
static BOOL __stdcall CSettingsStoreSP::SetRuntimeClass(CRuntimeClass* pRTI);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pRTI`  
 Um ponteiro para as informações de classe de tempo de execução para uma classe derivada do [CSettingsStore classe](../../mfc/reference/csettingsstore-class.md).  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se for bem-sucedida; `FALSE` se a classe identificado por `pRTI` não é derivado de `CSettingsStore`.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar o [CSettingsStoreSP classe](../../mfc/reference/csettingsstoresp-class.md) para derivar as classes de `CSettingsStore`. Use o método `SetRuntimeClass` se você deseja criar objetos de uma classe personalizada que é derivada de `CSettingsStore`.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CSettingsStore](../../mfc/reference/csettingsstore-class.md)
