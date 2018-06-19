---
title: Classe CCriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CCriticalSection
- AFXMT/CCriticalSection
- AFXMT/CCriticalSection::CCriticalSection
- AFXMT/CCriticalSection::Lock
- AFXMT/CCriticalSection::Unlock
- AFXMT/CCriticalSection::m_sect
dev_langs:
- C++
helpviewer_keywords:
- CCriticalSection [MFC], CCriticalSection
- CCriticalSection [MFC], Lock
- CCriticalSection [MFC], Unlock
- CCriticalSection [MFC], m_sect
ms.assetid: f776f74b-5b0b-4f32-9c13-2b8e4a0d7b2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1d6e713f6d5238d99af8f9311eb05a4b2dd39f7b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33353899"
---
# <a name="ccriticalsection-class"></a>Classe CCriticalSection
Representa uma "seção crítica" — um objeto de sincronização que permite que um segmento por vez para acessar um recurso ou uma seção de código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCriticalSection : public CSyncObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCriticalSection::CCriticalSection](#ccriticalsection)|Constrói um objeto `CCriticalSection`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCriticalSection::Lock](#lock)|Usar para acessar o `CCriticalSection` objeto.|  
|[CCriticalSection::Unlock](#unlock)|Libera o objeto `CCriticalSection`.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCriticalSection::operator CRITICAL_SECTION *](#operator_critical_section_star)|Recupera um ponteiro para o interno **CRITICAL_SECTION** objeto.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCriticalSection::m_sect](#m_sect)|Um **CRITICAL_SECTION** objeto.|  
  
## <a name="remarks"></a>Comentários  
 Seções críticas são úteis quando apenas um thread por vez pode ter permissão para modificar dados ou algum outro recurso controlado. Por exemplo, adicionando nós a uma lista vinculada é um processo que só deve ser permitido por um segmento por vez. Usando um `CCriticalSection` objeto para controlar a lista vinculada, somente um segmento por vez pode obter acesso à lista.  
  
> [!NOTE]
>  A funcionalidade do `CCriticalSection` classe é fornecida por um Win32 real **CRITICAL_SECTION** objeto.  
  
 Seções críticas são usadas em vez de mutexes (consulte [CMutex](../../mfc/reference/cmutex-class.md)) quando a velocidade é fundamental e o recurso não será usado pelos limites do processo.  
  
 Há dois métodos para usar um `CCriticalSection` objeto: autônomas e inseridas em uma classe.  
  
-   Método independente para usar um `CCriticalSection` do objeto, construa o `CCriticalSection` objeto quando ele é necessário. Após um retorno bem-sucedido de construtor, bloquear explicitamente o objeto com uma chamada para [bloqueio](#lock). Chamar [Unlock](#unlock) quando você terminar acessando a seção crítica. Esse método, ao mesmo tempo mais evidente a alguém ler seu código-fonte, é mais propenso a erros, você deve lembrar de bloquear e desbloquear a seção crítica antes e após o acesso.  
  
     Um método melhor é usar o [CSingleLock](../../mfc/reference/csinglelock-class.md) classe. Ele também tem um `Lock` e `Unlock` método, mas você não precisa se preocupar sobre como desbloquear o recurso se ocorrer uma exceção.  
  
-   Inserido método, você também pode compartilhar uma classe com vários threads, adicionando um `CCriticalSection`-membro de dados de tipo para a classe e o bloqueio de membro de dados quando necessário.  
  
 Para obter mais informações sobre como usar `CCriticalSection` objetos, consulte o artigo [Multithreading: como usar as Classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CSyncObject](../../mfc/reference/csyncobject-class.md)  
  
 `CCriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmt.h  
  
##  <a name="ccriticalsection"></a>  CCriticalSection::CCriticalSection  
 Constrói um objeto `CCriticalSection`.  
  
```  
CCriticalSection();
```  
  
### <a name="remarks"></a>Comentários  
 Para acessar ou liberar um `CCriticalSection` de objeto, criar um [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto e chame seu [bloqueio](../../mfc/reference/csinglelock-class.md#lock) e [Unlock](../../mfc/reference/csinglelock-class.md#unlock) funções de membro. Se o `CCriticalSection` objeto está sendo usado autônomo, chame seu [desbloquear](#unlock) a função de membro para liberá-lo.  
  
 Se o construtor Falha ao alocar a memória necessária do sistema, uma exceção de memória (do tipo [CMemoryException](../../mfc/reference/cmemoryexception-class.md)) é gerada automaticamente.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CCriticalSection::Lock](#lock).  
  
##  <a name="lock"></a>  CCriticalSection::Lock  
 Chame essa função de membro para acessar o objeto de seção crítica.  
  
```  
BOOL Lock();  
BOOL Lock(DWORD dwTimeout);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwTimeout`  
 `Lock` ignora esse valor de parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 `Lock` é uma chamada de bloqueio não retornará até que o objeto de seção crítica é sinalizado (torna-se disponível).  
  
 Se necessitar de atingiu o tempo de espera, você pode usar um [CMutex](../../mfc/reference/cmutex-class.md) do objeto, em vez de um `CCriticalSection` objeto.  
  
 Se `Lock` Falha ao alocar a memória de sistema necessários, uma exceção de memória (do tipo [CMemoryException](../../mfc/reference/cmemoryexception-class.md)) é gerada automaticamente.  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra a abordagem de seção crítica aninhada controlando o acesso a um recurso compartilhado (estático `_strShared` objeto) usando um compartilhado `CCriticalSection` objeto. O `SomeMethod` função demonstra um recurso compartilhado de atualização de maneira segura.  
  
 [!code-cpp[NVC_MFC_Utilities#11](../../mfc/codesnippet/cpp/ccriticalsection-class_1.h)]  
  
##  <a name="m_sect"></a>  CCriticalSection::m_sect  
 Contém um objeto de seção crítica que é usado por todos os `CCriticalSection` métodos.  
  
```  
CRITICAL_SECTION m_sect;  
```  
  
##  <a name="operator_critical_section_star"></a>  CCriticalSection::operator CRITICAL_SECTION *  
 Recupera um **CRITICAL_SECTION** objeto.  
  
```  
operator CRITICAL_SECTION*();
```   
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para recuperar um ponteiro para o interno **CRITICAL_SECTION** objeto.  
  
##  <a name="unlock"></a>  CCriticalSection::Unlock  
 Versões de `CCriticalSection` objeto para uso por outro thread.  
  
```  
BOOL Unlock();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CCriticalSection` objeto foi adquirido pelo thread e a versão foi bem sucedida; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o `CCriticalSection` está sendo usado autônomos, `Unlock` deve ser chamado imediatamente depois de concluir o uso do recurso controlado pela seção crítica. Se um [CSingleLock](../../mfc/reference/csinglelock-class.md) objeto está sendo usado, `CCriticalSection::Unlock` será chamado, o objeto de bloqueio `Unlock` função de membro.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CCriticalSection::Lock](#lock).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CSyncObject](../../mfc/reference/csyncobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CMutex](../../mfc/reference/cmutex-class.md)
