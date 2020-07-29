---
title: 'TN059: usando macros de conversão do MFC MBCS-Unicode'
ms.date: 11/04/2016
helpviewer_keywords:
- MFCANS32.DLL
- Unicode [MFC], conversion macros
- Unicode [MFC], OLE interfaces
- conversion macros [MFC]
- converting Unicode
- MBCS [MFC], conversion macros
- macros [MFC], MBCS conversion macros
- TN059
ms.assetid: a2aab748-94d0-4e2f-8447-3bd07112a705
ms.openlocfilehash: d689e87b8f2804fe99804c6ca37a48bac01df263
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182727"
---
# <a name="tn059-using-mfc-mbcsunicode-conversion-macros"></a>TN059: usando macros de conversão MBCS/Unicode MFC

> [!NOTE]
> A observação técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice de documentação online.

Esta observação descreve como usar as macros para a conversão MBCS/Unicode, que são definidas em AFXPRIV. T. Essas macros são mais úteis se o seu aplicativo lida diretamente com a API OLE ou por algum motivo, geralmente precisa converter entre Unicode e MBCS.

## <a name="overview"></a>Visão geral

No MFC 3. x, uma DLL especial foi usada (MFCANS32.DLL) para converter automaticamente entre o Unicode e o MBCS quando as interfaces OLE eram chamadas. Essa DLL era uma camada quase transparente que permitia que aplicativos OLE fossem gravados como se as APIs e interfaces OLE fossem MBCS, mesmo que sejam sempre Unicode (exceto no Macintosh). Embora essa camada tenha sido conveniente e permitisse que os aplicativos fossem portados rapidamente do Win16 para o Win32 (MFC, Microsoft Word, Microsoft Excel e VBA, sejam apenas alguns dos aplicativos da Microsoft que usaram essa tecnologia), às vezes houve um impacto significativo no desempenho. Por esse motivo, o MFC 4. x não usa essa DLL e, em vez disso, conversa diretamente com as interfaces OLE do Unicode. Para fazer isso, o MFC precisa converter para Unicode em MBCS ao fazer uma chamada para uma interface OLE e, muitas vezes, precisa converter para MBCS do Unicode ao implementar uma interface OLE. Para lidar com isso de forma eficiente e fácil, várias macros foram criadas para facilitar essa conversão.

Um dos maiores obstáculos da criação desse conjunto de macros é a alocação de memória. Como as cadeias de caracteres não podem ser convertidas em vigor, a nova memória para armazenar os resultados convertidos deve ser alocada. Isso pode ter sido feito com um código semelhante ao seguinte:

```
// we want to convert an MBCS string in lpszA
int nLen = MultiByteToWideChar(CP_ACP,
    0,
    lpszA, -1,
    NULL,
    NULL);

LPWSTR lpszW = new WCHAR[nLen];
MultiByteToWideChar(CP_ACP,
    0,
    lpszA, -1,
    lpszW,
    nLen);

// use it to call OLE here
pI->SomeFunctionThatNeedsUnicode(lpszW);

// free the string
delete[] lpszW;
```

Essa abordagem como uma série de problemas. O principal problema é que é muito código para escrever, testar e depurar. Algo que era uma chamada de função simples, agora é muito mais complexo. Além disso, há uma sobrecarga de tempo de execução significativa ao fazer isso. A memória deve ser alocada no heap e liberada toda vez que uma conversão é feita. Por fim, o código acima precisaria ter uma `#ifdefs` adição apropriada para compilações de Unicode e de Macintosh (que não exigem essa conversão em vigor).

A solução que criamos é criar algumas macros que 1) mascarar a diferença entre as várias plataformas e 2) usar um esquema de alocação de memória eficiente e 3) são fáceis de inserir no código-fonte existente. Aqui está um exemplo de uma das definições:

```
#define A2W(lpa) (\
((LPCSTR)lpa == NULL) NULL : (\
    _convert = (strnlen(lpa)+1),\
    AfxA2WHelper((LPWSTR) alloca(_convert*2),
    lpa,
    _convert)\)\)
```

Usar essa macro em vez do código acima e as coisas são muito mais simples:

```
// use it to call OLE here
USES_CONVERSION;
pI->SomeFunctionThatNeedsUnicode(T2OLE(lpszA));
```

Há chamadas extras em que a conversão é necessária, mas usar as macros é simples e eficaz.

A implementação de cada macro usa a função _alloca () para alocar memória da pilha em vez do heap. Alocar memória da pilha é muito mais rápido do que alocar memória no heap, e a memória é liberada automaticamente quando a função é encerrada. Além disso, as macros evitam chamar `MultiByteToWideChar` (ou `WideCharToMultiByte` ) mais de uma vez. Isso é feito alocando um pouco mais de memória do que o necessário. Sabemos que um MBC será convertido em no máximo um **WCHAR** e que, para cada **WCHAR** , teremos um máximo de dois bytes de MBC. Alocando um pouco mais do que o necessário, mas sempre o suficiente para lidar com a conversão, a segunda chamada de segundo chamadas para a função de conversão é evitada. A chamada para a função auxiliar `AfxA2Whelper` reduz o número de Pushes de argumento que devem ser feitos para executar a conversão (isso resulta em um código menor do que se ele for chamado `MultiByteToWideChar` diretamente).

Para que as macros tenham espaço para armazenar o comprimento temporário, é necessário declarar uma variável local chamada _convert que faz isso em cada função que usa as macros de conversão. Isso é feito invocando a macro USES_CONVERSION, como mostrado acima no exemplo.

Há macros de conversão genéricas e macros específicas de OLE. Esses dois conjuntos de macros diferentes são discutidos abaixo. Todas as macros residem em AFXPRIV. T.

## <a name="generic-conversion-macros"></a>Macros de conversão genérica

As macros de conversão genérica formam o mecanismo subjacente. O exemplo de macro e a implementação mostrados na seção anterior, A2W, são uma macro "genérica". Ele não está relacionado especificamente ao OLE. O conjunto de macros genéricas está listado abaixo:

```
A2CW      (LPCSTR) -> (LPCWSTR)
A2W      (LPCSTR) -> (LPWSTR)
W2CA      (LPCWSTR) -> (LPCSTR)
W2A      (LPCWSTR) -> (LPSTR)
```

Além de fazer conversões de texto, também há macros e funções auxiliares para conversão `TEXTMETRIC` , `DEVMODE` , `BSTR` e cadeias de caracteres alocadas em OLE. Essas macros estão além do escopo desta discussão – consulte AFXPRIV. H para obter mais informações sobre essas macros.

## <a name="ole-conversion-macros"></a>Macros de conversão OLE

As macros de conversão OLE são projetadas especificamente para manipular funções que esperam caracteres **OLESTR** . Se você examinar os cabeçalhos OLE, verá muitas referências a **LPCOLESTR** e **OLECHAR**. Esses tipos são usados para fazer referência ao tipo de caracteres usado em interfaces OLE de uma forma que não seja específica para a plataforma. **OLECHAR** mapeia para **`char`** nas plataformas Win16 e Macintosh e **WCHAR** no Win32.

Para manter o número de diretivas **#ifdef** no código MFC para um mínimo, temos uma macro semelhante para cada conversão em que as cadeias de caracteres OLE estão envolvidas. As macros a seguir são as mais comumente usadas:

```
T2COLE   (LPCTSTR) -> (LPCOLESTR)
T2OLE   (LPCTSTR) -> (LPOLESTR)
OLE2CT   (LPCOLESTR) -> (LPCTSTR)
OLE2T   (LPCOLESTR) -> (LPCSTR)
```

Novamente, há macros semelhantes para fazer TEXTMETRIC, DEVMODE, BSTR e cadeias de caracteres alocadas em OLE. Consulte AFXPRIV. H para obter mais informações.

## <a name="other-considerations"></a>Outras considerações

Não use as macros em um loop rígido. Por exemplo, você não deseja escrever o seguinte tipo de código:

```cpp
void BadIterateCode(LPCTSTR lpsz)
{
    USES_CONVERSION;
    for (int ii = 0; ii <10000; ii++)
    pI->SomeMethod(ii, T2COLE(lpsz));

}
```

O código acima poderia resultar na alocação de megabytes de memória na pilha, dependendo do conteúdo da cadeia de caracteres `lpsz` ! Também leva tempo para converter a cadeia de caracteres para cada iteração do loop. Em vez disso, mova essas conversões constantes para fora do loop:

```cpp
void MuchBetterIterateCode(LPCTSTR lpsz)
{
    USES_CONVERSION;
    LPCOLESTR lpszT = T2COLE(lpsz);

    for (int ii = 0; ii <10000; ii++)
    pI->SomeMethod(ii, lpszT);

}
```

Se a cadeia de caracteres não for constante, encapsulará a chamada de método em uma função. Isso permitirá que o buffer de conversão seja liberado a cada vez. Por exemplo:

```cpp
void CallSomeMethod(int ii, LPCTSTR lpsz)
{
    USES_CONVERSION;
    pI->SomeMethod(ii, T2COLE(lpsz));

}

void MuchBetterIterateCode2(LPCTSTR* lpszArray)
{
    for (int ii = 0; ii <10000; ii++)
    CallSomeMethod(ii, lpszArray[ii]);

}
```

Nunca retorne o resultado de uma das macros, a menos que o valor de retorno implica fazer uma cópia dos dados antes do retorno. Por exemplo, esse código é inadequado:

```
LPTSTR BadConvert(ISomeInterface* pI)
{
    USES_CONVERSION;
    LPOLESTR lpsz = NULL;
    pI->GetFileName(&lpsz);

LPTSTR lpszT = OLE2T(lpsz);

    CoMemFree(lpsz);

return lpszT; // bad! returning alloca memory
}
```

O código acima poderia ser corrigido alterando o valor de retorno para algo que copia o valor:

```
CString BetterConvert(ISomeInterface* pI)
{
    USES_CONVERSION;
    LPOLESTR lpsz = NULL;
    pI->GetFileName(&lpsz);

LPTSTR lpszT = OLE2T(lpsz);

    CoMemFree(lpsz);

return lpszT; // CString makes copy
}
```

As macros são fáceis de usar e fáceis de inserir em seu código, mas como você pode perceber com base nas advertências acima, você precisa ter cuidado ao usá-las.

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
