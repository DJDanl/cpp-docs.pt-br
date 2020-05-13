---
title: Classe CCriticalSection
ms.date: 11/04/2016
f1_keywords:
- CCriticalSection
- AFXMT/CCriticalSection
- AFXMT/CCriticalSection::CCriticalSection
- AFXMT/CCriticalSection::Lock
- AFXMT/CCriticalSection::Unlock
- AFXMT/CCriticalSection::m_sect
helpviewer_keywords:
- CCriticalSection [MFC], CCriticalSection
- CCriticalSection [MFC], Lock
- CCriticalSection [MFC], Unlock
- CCriticalSection [MFC], m_sect
ms.assetid: f776f74b-5b0b-4f32-9c13-2b8e4a0d7b2b
ms.openlocfilehash: d79199a332f6930619e6b4995b04bc590b6ea580
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369372"
---
# <a name="ccriticalsection-class"></a>Classe CCriticalSection

Representa uma "seção crítica" — um objeto de sincronização que permite que um segmento de cada vez acesse um recurso ou seção de código.

## <a name="syntax"></a>Sintaxe

```
class CCriticalSection : public CSyncObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCriticalSection::CCriticalSection](#ccriticalsection)|Constrói um objeto `CCriticalSection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCriticalSection::Bloqueio](#lock)|Use para ter `CCriticalSection` acesso ao objeto.|
|[CCriticalSection::Unlock](#unlock)|Libera o objeto `CCriticalSection`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCriticalSection::CRITICAL_SECTION do operador*](#operator_critical_section_star)|Recupera um ponteiro para o objeto interno CRITICAL_SECTION.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCriticalSection::m_sect](#m_sect)|Um objeto CRITICAL_SECTION.|

## <a name="remarks"></a>Comentários

Seções críticas são úteis quando apenas um segmento de cada vez pode ser permitido modificar dados ou algum outro recurso controlado. Por exemplo, adicionar nomes a uma lista vinculada é um processo que só deve ser permitido por um segmento de cada vez. Usando um `CCriticalSection` objeto para controlar a lista vinculada, apenas um segmento de cada vez pode ter acesso à lista.

> [!NOTE]
> A funcionalidade da `CCriticalSection` classe é fornecida por um objeto de CRITICAL_SECTION Win32 real.

Seções críticas são usadas em vez de mutexes (ver [CMutex](../../mfc/reference/cmutex-class.md)) quando a velocidade é crítica e o recurso não será usado entre os limites do processo.

Existem dois métodos `CCriticalSection` para usar um objeto: autônomo e incorporado em uma classe.

- Método autônomo Para usar um `CCriticalSection` objeto autônomo, `CCriticalSection` construa o objeto quando necessário. Após um retorno bem-sucedido da construtora, bloqueie explicitamente o objeto com uma chamada para [Bloquear](#lock). [Ligue desbloqueie](#unlock) quando terminar de acessar a seção crítica. Este método, embora mais claro para alguém que lê seu código fonte, é mais propenso a erros, pois você deve se lembrar de bloquear e desbloquear a seção crítica antes e depois do acesso.

   Um método mais preferível é usar a classe [CSingleLock.](../../mfc/reference/csinglelock-class.md) Ele também `Lock` tem `Unlock` um método, mas você não precisa se preocupar em desbloquear o recurso se ocorrer uma exceção.

- Método incorporado Você também pode compartilhar uma classe `CCriticalSection`com vários segmentos adicionando um membro de dados de tipo à classe e bloqueando o membro de dados quando necessário.

Para obter mais `CCriticalSection` informações sobre o uso de objetos, consulte o artigo [Multithreading: Como usar as classes de sincronização](../../parallel/multithreading-how-to-use-the-synchronization-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Csyncobject](../../mfc/reference/csyncobject-class.md)

`CCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmt.h

## <a name="ccriticalsectionccriticalsection"></a><a name="ccriticalsection"></a>CCriticalSection::CCriticalSection

Constrói um objeto `CCriticalSection`.

```
CCriticalSection();
```

### <a name="remarks"></a>Comentários

Para acessar ou `CCriticalSection` liberar um objeto, crie um objeto [CSingleLock](../../mfc/reference/csinglelock-class.md) e chame suas funções de membro [Bloquear](../../mfc/reference/csinglelock-class.md#lock) e [Desbloquear.](../../mfc/reference/csinglelock-class.md#unlock) Se `CCriticalSection` o objeto estiver sendo usado autônomo, chame a função [Desbloquear](#unlock) membro para liberá-lo.

Se o construtor não conseguir alocar a memória do sistema necessária, uma exceção de memória (do tipo [CMemoryException)](../../mfc/reference/cmemoryexception-class.md)será lançada automaticamente.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CCriticalSection::Lock](#lock).

## <a name="ccriticalsectionlock"></a><a name="lock"></a>CCriticalSection::Bloqueio

Chame esta função de membro para obter acesso ao objeto da seção crítica.

```
BOOL Lock();
BOOL Lock(DWORD dwTimeout);
```

### <a name="parameters"></a>Parâmetros

*Dwtimeout*<br/>
`Lock`ignora esse valor de parâmetro.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Lock`é uma chamada de bloqueio que não retornará até que o objeto da seção crítica seja sinalizado (torna-se disponível).

Se as esperas cronometradas forem necessárias, você `CCriticalSection` pode usar um objeto [CMutex](../../mfc/reference/cmutex-class.md) em vez de um objeto.

Se `Lock` falhar em alocar a memória necessária do sistema, uma exceção de memória (do tipo [CMemoryException)](../../mfc/reference/cmemoryexception-class.md)será lançada automaticamente.

### <a name="example"></a>Exemplo

Este exemplo demonstra a abordagem de seção crítica aninhada `_strShared` controlando o `CCriticalSection` acesso a um recurso compartilhado (o objeto estático) usando um objeto compartilhado. A `SomeMethod` função demonstra a atualização de um recurso compartilhado de forma segura.

[!code-cpp[NVC_MFC_Utilities#11](../../mfc/codesnippet/cpp/ccriticalsection-class_1.h)]

## <a name="ccriticalsectionm_sect"></a><a name="m_sect"></a>CCriticalSection::m_sect

Contém um objeto de seção `CCriticalSection` crítico que é usado por todos os métodos.

```
CRITICAL_SECTION m_sect;
```

## <a name="ccriticalsectionoperator-critical_section"></a><a name="operator_critical_section_star"></a>CCriticalSection::CRITICAL_SECTION do operador*

Recupera um objeto CRITICAL_SECTION.

```
operator CRITICAL_SECTION*();
```

### <a name="remarks"></a>Comentários

Chame esta função para recuperar um ponteiro para o objeto interno CRITICAL_SECTION.

## <a name="ccriticalsectionunlock"></a><a name="unlock"></a>CCriticalSection::Unlock

Libera o `CCriticalSection` objeto para uso por outro segmento.

```
BOOL Unlock();
```

### <a name="return-value"></a>Valor retornado

Não zero `CCriticalSection` se o objeto era propriedade do segmento e a liberação foi bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se `CCriticalSection` o estiver sendo usado `Unlock` autônomo, deve ser chamado imediatamente após completar o uso do recurso controlado pela seção crítica. Se um objeto [CSingleLock](../../mfc/reference/csinglelock-class.md) `CCriticalSection::Unlock` estiver sendo usado, será `Unlock` chamado pela função de membro do objeto de bloqueio.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CCriticalSection::Lock](#lock).

## <a name="see-also"></a>Confira também

[Classe CSyncObject](../../mfc/reference/csyncobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMutex](../../mfc/reference/cmutex-class.md)
