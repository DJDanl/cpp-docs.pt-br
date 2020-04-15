---
title: 'TN059: Usando macros de conversão MFC MBCS-Unicode'
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
ms.openlocfilehash: 0d63a87d0fddde30dd5cbb18207297a345d74b9c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366585"
---
# <a name="tn059-using-mfc-mbcsunicode-conversion-macros"></a>TN059: usando macros de conversão MBCS/Unicode MFC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve como usar as macros para conversão MBCS/Unicode, que são definidas no AFXPRIV. H. Essas macros são mais úteis se seu aplicativo lida diretamente com a API OLE ou, por algum motivo, muitas vezes precisa converter entre Unicode e MBCS.

## <a name="overview"></a>Visão geral

No MFC 3.x, foi utilizada uma DLL especial (MFCANS32. DLL) para converter automaticamente entre Unicode e MBCS quando as interfaces OLE foram chamadas. Esta DLL era uma camada quase transparente que permitia que os aplicativos OLE fossem escritos como se as APIs e interfaces oLE fossem MBCS, embora sejam sempre Unicode (exceto no Macintosh). Embora essa camada fosse conveniente e permitisse que os aplicativos fossem rapidamente portados do Win16 para o Win32 (MFC, Microsoft Word, Microsoft Excel e VBA, são apenas alguns dos aplicativos da Microsoft que usaram essa tecnologia), ele teve um desempenho às vezes significativo. Por essa razão, o MFC 4.x não usa este DLL e, em vez disso, conversa diretamente com as interfaces Unicode OLE. Para fazer isso, o MFC precisa converter para Unicode para MBCS ao fazer uma chamada para uma interface OLE, e muitas vezes precisa converter para MBCS do Unicode ao implementar uma interface OLE. Para lidar com isso de forma eficiente e fácil, uma série de macros foram criadas para facilitar essa conversão.

Um dos maiores obstáculos para criar esse conjunto de macros é a alocação de memória. Como as strings não podem ser convertidas no lugar, uma nova memória para conter os resultados convertidos deve ser alocada. Isso poderia ter sido feito com código semelhante ao seguinte:

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

Essa abordagem como uma série de problemas. O principal problema é que é um monte de código para escrever, testar e depurar. Algo que era uma simples chamada de função, agora é muito mais complexo. Além disso, há uma sobrecarga de tempo de execução significativa ao fazê-lo. A memória tem que ser alocada no heap e liberada cada vez que uma conversão é feita. Finalmente, o código acima precisaria `#ifdefs` ter adicionado apropriado para compilações Unicode e Macintosh (que não exigem que essa conversão ocorra).

A solução que criamos é criar algumas macros que 1) mascarar a diferença entre as várias plataformas, e 2) usar um esquema eficiente de alocação de memória, e 3) são fáceis de inserir no código-fonte existente. Aqui está um exemplo de uma das definições:

```
#define A2W(lpa) (\
((LPCSTR)lpa == NULL) NULL : (\
    _convert = (strnlen(lpa)+1),\
    AfxA2WHelper((LPWSTR) alloca(_convert*2),
    lpa,
    _convert)\)\)
```

Usando esta macro em vez do código acima e as coisas são muito mais simples:

```
// use it to call OLE here
USES_CONVERSION;
pI->SomeFunctionThatNeedsUnicode(T2OLE(lpszA));
```

Existem chamadas extras onde a conversão é necessária, mas usar as macros é simples e eficaz.

A implementação de cada macro usa a função _alloca() para alocar memória da pilha em vez do heap. Alocar memória da pilha é muito mais rápido do que alocar memória no heap, e a memória é automaticamente liberada quando a função é saída. Além disso, as macros evitam ligar `MultiByteToWideChar` (ou `WideCharToMultiByte`) mais de uma vez. Isso é feito alocando um pouco mais de memória do que é necessário. Sabemos que um MBC se converterá em no máximo um **WCHAR** e que para cada **WCHAR** teremos no máximo dois bytes MBC. Ao alocar um pouco mais do que o necessário, mas sempre o suficiente para lidar com a conversão a segunda chamada de segunda chamada para a função de conversão é evitada. A chamada para a `AfxA2Whelper` função auxiliar reduz o número de empurrões de argumento que devem ser feitos para `MultiByteToWideChar` realizar a conversão (isso resulta em código menor do que se ele chamado diretamente).

Para que as macros tenham espaço para armazenar o comprimento temporário, é necessário declarar uma variável local chamada _convert que faz isso em cada função que usa as macros de conversão. Isso é feito invocando a macro USES_CONVERSION como visto acima no exemplo.

Existem macros de conversão genéricas e macros específicas oLE. Estes dois conjuntos de macros diferentes são discutidos abaixo. Todas as macros residem no AFXPRIV. H.

## <a name="generic-conversion-macros"></a>Macros de conversão genérica

As macros de conversão genérica formam o mecanismo subjacente. O exemplo de macro e a implementação mostrados na seção anterior, A2W, é uma dessas macros "genéricas". Não está relacionado especificamente ao OLE. O conjunto de macros genéricas está listado abaixo:

```
A2CW      (LPCSTR) -> (LPCWSTR)
A2W      (LPCSTR) -> (LPWSTR)
W2CA      (LPCWSTR) -> (LPCSTR)
W2A      (LPCWSTR) -> (LPSTR)
```

Além de fazer conversões de texto, há também macros `DEVMODE` `BSTR`e funções auxiliares para converter `TEXTMETRIC`, , e strings alocadas oLE. Essas macros estão além do escopo desta discussão - consulte AFXPRIV. H para obter mais informações sobre essas macros.

## <a name="ole-conversion-macros"></a>Macros de conversão OLE

As macros de conversão OLE são projetadas especificamente para funções de manuseio que esperam caracteres **OLESTR.** Se você examinar os cabeçalhos OLE, verá muitas referências a **LPCOLESTR** e **OLECHAR**. Esses tipos são usados para se referir ao tipo de caracteres usados em interfaces OLE de uma forma que não é específica para a plataforma. **OLECHAR** mapeia para **char** em plataformas Win16 e Macintosh e **WCHAR** em Win32.

A fim de manter o número de **diretivas #ifdef** no código MFC para um mínimo, temos uma macro semelhante para cada conversão que onde as strings OLE estão envolvidas. As seguintes macros são as mais utilizadas:

```
T2COLE   (LPCTSTR) -> (LPCOLESTR)
T2OLE   (LPCTSTR) -> (LPOLESTR)
OLE2CT   (LPCOLESTR) -> (LPCTSTR)
OLE2T   (LPCOLESTR) -> (LPCSTR)
```

Novamente, existem macros semelhantes para fazer strings alocadas em TEXTMETRIC, DEVMODE, BSTR e OLE. Consulte a AFXPRIV. H para mais informações.

## <a name="other-considerations"></a>Outras considerações

Não use as macros em um loop apertado. Por exemplo, você não deseja escrever o seguinte tipo de código:

```
void BadIterateCode(LPCTSTR lpsz)
{
    USES_CONVERSION;
    for (int ii = 0; ii <10000; ii++)
    pI->SomeMethod(ii, T2COLE(lpsz));

}
```

O código acima pode resultar na alocação de megabytes de memória `lpsz` na pilha, dependendo do conteúdo da string! Também leva tempo para converter a seqüência para cada iteração do loop. Em vez disso, mova essas conversões constantes para fora do loop:

```
void MuchBetterIterateCode(LPCTSTR lpsz)
{
    USES_CONVERSION;
    LPCOLESTR lpszT = T2COLE(lpsz);

    for (int ii = 0; ii <10000; ii++)
    pI->SomeMethod(ii, lpszT);

}
```

Se a seqüência não for constante, então encapsule a chamada do método em uma função. Isso permitirá que o buffer de conversão seja liberado cada vez. Por exemplo:

```
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

Nunca devolva o resultado de uma das macros, a menos que o valor de retorno impetede fazer uma cópia dos dados antes do retorno. Por exemplo, este código é ruim:

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

As macros são fáceis de usar e fáceis de inserir em seu código, mas como você pode dizer pelas ressalvas acima, você precisa ter cuidado ao usá-las.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
