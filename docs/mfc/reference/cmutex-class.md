---
title: Classe CMutex | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMutex
- AFXMT/CMutex
- AFXMT/CMutex::CMutex
dev_langs:
- C++
helpviewer_keywords:
- CMutex class
- synchronization classes, CMutex class
- synchronization objects, mutex
- mutex
ms.assetid: 6330c050-4f01-4195-a099-2029b92f8cf1
caps.latest.revision: 22
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 159f2e02dfe44d74ebcaad687a23cef734b61fc9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmutex-class"></a>Classe CMutex
Representa um "mutex" — um objeto de sincronização que permite que um thread mutuamente acessem um recurso.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMutex : public CSyncObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMutex::CMutex](#cmutex)|Constrói um objeto `CMutex`.|  
  
## <a name="remarks"></a>Comentários  
 Exclusões mútuas são úteis quando apenas um thread por vez pode ter permissão para modificar os dados ou algum outro recurso controlado. Por exemplo, a adição de nós em uma lista vinculada é um processo que só deve ser permitido por um thread por vez. Usando um `CMutex` objeto para controlar a lista vinculada, somente um thread por vez pode obter acesso à lista.  
  
 Para usar um `CMutex` de objeto, construir o `CMutex` objeto quando ele é necessário. Especifique o nome do mutex deseja esperar e que seu aplicativo deve possuir inicialmente. Você pode acessar o mutex quando o construtor retorna. Chamar [CSyncObject::Unlock](../../mfc/reference/csyncobject-class.md#unlock) quando você terminar o acesso ao recurso controlado.  
  
 Um método alternativo para o uso de `CMutex` objetos é adicionar uma variável do tipo `CMutex` como um membro de dados para a classe que você deseja o controle. Durante a construção do objeto controlado, chame o construtor do `CMutex` membro de dados especificando se o mutex pertence inicialmente, o nome do mutex (se ele será usado nos limites do processo) e os atributos de segurança desejados.  
  
 Para acessar os recursos controlados por `CMutex` objetos dessa maneira, primeiro crie uma variável de qualquer tipo [CSingleLock](../../mfc/reference/csinglelock-class.md) ou tipo [CMultiLock](../../mfc/reference/cmultilock-class.md) na função de membro de acesso do recurso. Em seguida, chamar o objeto de bloqueio `Lock` função de membro (por exemplo, [CSingleLock::Lock](../../mfc/reference/csinglelock-class.md#lock)). Neste ponto, o thread será em acessar o recurso, aguarde o recurso a ser lançado e obter acesso ou aguardar o tempo limite, Falha ao acessar o recurso e o recurso a ser liberado. Em qualquer caso, o recurso foi acessado de forma segura para thread. Para liberar o recurso, use o objeto de bloqueio `Unlock` função de membro (por exemplo, [CSingleLock::Unlock](../../mfc/reference/csinglelock-class.md#unlock)), ou permitir que o objeto de bloqueio ficar fora do escopo.  
  
 Para obter mais informações sobre como usar o `CMutex` objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CMutex`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="cmutex"></a>CMutex::CMutex  
 Constrói um nome ou sem nome `CMutex` objeto.  
  
```  
CMutex(
    BOOL bInitiallyOwn = FALSE,  
    LPCTSTR lpszName = NULL,  
    LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bInitiallyOwn`  
 Especifica se a criação de thread a `CMutex` objeto inicialmente tem acesso ao recurso controlado pelo mutex.  
  
 `lpszName`  
 Nome do objeto de `CMutex` . Se houver outro mutex com o mesmo nome, `lpszName` deve ser fornecido se o objeto será usado nos limites do processo. Se **nulo**, mutex será sem nome. Se o nome corresponde a um mutex existente, o construtor cria um novo `CMutex` objeto que referencia o mutex do nome. Se o nome corresponde a um objeto de sincronização existente que não é um mutex, a construção falhará.  
  
 `lpsaAttribute`  
 Atributos de segurança para o objeto de mutex. Para obter uma descrição completa dessa estrutura, consulte [SECURITY_ATTRIBUTES](http://msdn.microsoft.com/library/windows/desktop/aa379560) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Para acessar ou liberar um `CMutex` de objeto, criar um [CMultiLock](../../mfc/reference/cmultilock-class.md) ou [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chamar seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro. Se o `CMutex` objeto está sendo usado autônomo, chame seu `Unlock` função de membro para liberá-lo.  
  
> [!IMPORTANT]
>  Depois de criar o `CMutex` de objeto, use [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) para garantir que o mutex ainda não existir. Se o mutex existia inesperadamente, isso pode indicar um processo não autorizado é apropriação indevida e pode ser pretende usar o mutex de maneira mal-intencionada. Nesse caso, o procedimento sensível à segurança recomendado é fechar o identificador e continuará como se houve uma falha na criação do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




