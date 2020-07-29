---
title: Classe CWaitCursor
ms.date: 11/04/2016
f1_keywords:
- CWaitCursor
- AFXWIN/CWaitCursor
- AFXWIN/CWaitCursor::CWaitCursor
- AFXWIN/CWaitCursor::Restore
helpviewer_keywords:
- CWaitCursor [MFC], CWaitCursor
- CWaitCursor [MFC], Restore
ms.assetid: 5dfae2ff-d7b6-4383-b0ad-91e0868c67b3
ms.openlocfilehash: dfeedad18b3ebcefedff446699f074c86037a4a3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222869"
---
# <a name="cwaitcursor-class"></a>Classe CWaitCursor

Fornece uma maneira de uma linha para mostrar um cursor de espera, que geralmente é exibido como uma ampulheta, enquanto você está fazendo uma operação demorada.

## <a name="syntax"></a>Sintaxe

```
class CWaitCursor
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWaitCursor::CWaitCursor](#cwaitcursor)|Constrói um `CWaitCursor` objeto e exibe o cursor de espera.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWaitCursor:: Restore](#restore)|Restaura o cursor de espera após sua alteração.|

## <a name="remarks"></a>Comentários

`CWaitCursor`Não tem uma classe base.

Boas práticas de programação do Windows exigem que você exiba um cursor de espera sempre que estiver executando uma operação que leva uma quantidade de tempo perceptível.

Para exibir um cursor de espera, basta definir uma `CWaitCursor` variável antes do código que executa a operação demorada. O construtor do objeto faz com que o cursor de espera seja exibido automaticamente.

Quando o objeto sai do escopo (no final do bloco em que o `CWaitCursor` objeto é declarado), seu destruidor define o cursor para o cursor anterior. Em outras palavras, o objeto executa a limpeza necessária automaticamente.

> [!NOTE]
> Devido a como os construtores e destruidores funcionam, os `CWaitCursor` objetos são sempre declarados como variáveis locais – eles nunca são declarados como variáveis globais nem são alocados com **`new`** .

Se você executar uma operação que pode fazer com que o cursor seja alterado, como exibir uma caixa de mensagem ou caixa de diálogo, chame a função de membro [Restore](#restore) para restaurar o cursor de espera. Não há problema em chamar `Restore` mesmo quando um cursor de espera é exibido no momento.

Outra maneira de exibir um cursor de espera é usar a combinação de [CCmdTarget:: BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor), [CCmdTarget:: EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)e, talvez, [CCmdTarget:: RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor). No entanto, o `CWaitCursor` é mais fácil de usar porque você não precisa definir o cursor para o cursor anterior quando concluiu a operação demorada.

> [!NOTE]
> O MFC define e restaura o cursor usando a função virtual [CWinApp::D owaitcursor](../../mfc/reference/cwinapp-class.md#dowaitcursor) . Você pode substituir essa função para fornecer um comportamento personalizado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CWaitCursor`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#62](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_1.cpp)]

## <a name="cwaitcursorcwaitcursor"></a><a name="cwaitcursor"></a>CWaitCursor::CWaitCursor

Para exibir um cursor de espera, basta declarar um `CWaitCursor` objeto antes do código que executa a operação demorada.

```
CWaitCursor();
```

### <a name="remarks"></a>Comentários

O construtor faz com que o cursor de espera seja exibido automaticamente.

Quando o objeto sai do escopo (no final do bloco em que o `CWaitCursor` objeto é declarado), seu destruidor define o cursor para o cursor anterior. Em outras palavras, o objeto executa a limpeza necessária automaticamente.

Você pode aproveitar o fato de que o destruidor é chamado no final do bloco (que pode ser antes do final da função) para tornar o cursor de espera ativo em apenas parte da sua função. Essa técnica é mostrada no segundo exemplo abaixo.

> [!NOTE]
> Devido a como os construtores e destruidores funcionam, os `CWaitCursor` objetos são sempre declarados como variáveis locais – eles nunca são declarados como variáveis globais, nem são alocados com **`new`** .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#63](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_2.cpp)]

## <a name="cwaitcursorrestore"></a><a name="restore"></a>CWaitCursor:: Restore

Para restaurar o cursor de espera, chame essa função depois de executar uma operação, como exibir uma caixa de mensagem ou caixa de diálogo, que pode alterar o cursor de espera para outro cursor.

```cpp
void Restore();
```

### <a name="remarks"></a>Comentários

Ele é OK para chamar `Restore` mesmo quando o cursor de espera é exibido no momento.

Se você precisar restaurar o cursor de espera enquanto estiver em uma função diferente daquela em que o `CWaitCursor` objeto é declarado, você pode chamar [CCmdTarget:: RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCWindowing#64](../../mfc/reference/codesnippet/cpp/cwaitcursor-class_3.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CCmdTarget:: BeginWaitCursor](../../mfc/reference/ccmdtarget-class.md#beginwaitcursor)<br/>
[CCmdTarget:: EndWaitCursor](../../mfc/reference/ccmdtarget-class.md#endwaitcursor)<br/>
[CCmdTarget:: RestoreWaitCursor](../../mfc/reference/ccmdtarget-class.md#restorewaitcursor)<br/>
[CWinApp::D oWaitCursor](../../mfc/reference/cwinapp-class.md#dowaitcursor)<br/>
[Como faço para: alterar o cursor do mouse em um aplicativo Microsoft Foundation Class](https://go.microsoft.com/fwlink/p/?linkid=128044)
