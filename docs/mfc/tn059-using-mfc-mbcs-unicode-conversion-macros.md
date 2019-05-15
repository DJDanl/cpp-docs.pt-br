---
title: 'TN059: Usando Macros de conversão MBCS-Unicode MFC'
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
ms.openlocfilehash: 6c182ff584404fb91de8ff5e8020ec2e6ef9f950
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611863"
---
# <a name="tn059-using-mfc-mbcsunicode-conversion-macros"></a>TN059: Usando Macros de conversão MBCS/Unicode MFC

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve como usar as macros de conversão MBCS/Unicode, que são definidas em AFXPRIV. H. Essas macros são mais úteis, se seu aplicativo lida diretamente com a API do OLE ou por algum motivo, geralmente precisa converter entre Unicode e MBCS.

## <a name="overview"></a>Visão geral

No MFC 3.x, foi de uma DLL especial usado (MFCANS32. DLL) para converter automaticamente entre Unicode e MBCS quando interfaces OLE foram chamados. Essa DLL foi uma camada transparente quase que permitiu aos aplicativos OLE a ser gravado como se as interfaces e APIs OLE foram MBCS, mesmo que eles sejam sempre Unicode (exceto no Macintosh). Embora essa camada foi conveniente e permitiu aos aplicativos fosse portado rapidamente do Win16 para Win32 (MFC, o Microsoft Word, o Microsoft Excel e o VBA, são apenas alguns dos aplicativos Microsoft que usou essa tecnologia), que tinha um desempenho significativo, às vezes, de ocorrências. Por esse motivo, o MFC 4.x não usa essa DLL e em vez disso, se comunica diretamente com as interfaces OLE do Unicode. Para fazer isso, o MFC precisa converter em Unicode em MBCS ao fazer uma chamada para uma interface OLE e geralmente precisa converter em MBCS de Unicode ao implementar uma interface OLE. Para tratar isso de forma eficiente e fácil, um número de macros foram criado para facilitar essa conversão.

Uma das maiores dificuldades de criar esse conjunto de macros é a alocação de memória. Porque as cadeias de caracteres não podem ser convertidas em vigor, a nova memória para armazenar os resultados convertidos deve ser alocada. Isso poderia ter sido feito com um código semelhante ao seguinte:

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

Essa abordagem como uma série de problemas. O principal problema é que ele é muito código para escrever, testar e depurar. Algo que era uma chamada de função simples, agora é muito mais complexo. Além disso, há um tempo de execução significativo sobrecarga ao fazer isso. Memória deve ser alocado no heap e liberado sempre que uma conversão é feita. Por fim, o código acima precisaria ter apropriado `#ifdefs` adicionado para compilações de Unicode e no Macintosh (que não exigem essa conversão para entrar em vigor).

A solução que criamos é criar algumas macros de código-fonte que 1) máscara a diferença entre as várias plataformas e 2) use um esquema de alocação de memória eficiente e 3) são mais fácil inserir à existente. Aqui está um exemplo de uma das definições:

```
#define A2W(lpa) (\
((LPCSTR)lpa == NULL) NULL : (\
    _convert = (strnlen(lpa)+1),\
    AfxA2WHelper((LPWSTR) alloca(_convert*2),
    lpa,
    _convert)\)\)
```

Usando este macro em vez do código acima e as coisas são muito mais simples:

```
// use it to call OLE here
USES_CONVERSION;
pI->SomeFunctionThatNeedsUnicode(T2OLE(lpszA));
```

Há chamadas extras em que a conversão é necessária, mas usar as macros é simples e eficiente.

A implementação de cada macro usa a função alloca () para alocar memória da pilha, em vez de heap. Alocação de memória da pilha é muito mais rápido que a alocação de memória no heap e a memória é liberada automaticamente quando a função é fechada. Além disso, as macros Evite chamar `MultiByteToWideChar` (ou `WideCharToMultiByte`) mais de uma vez. Isso é feito ao alocar um pouco mais memória do que é necessário. Sabemos que um MERCER irá converter no máximo uma **WCHAR** e que para cada **WCHAR** teremos um máximo de dois bytes MERCER. Alocando um pouco mais do que o necessário, mas sempre é suficiente para lidar com a conversão a segunda chamada segunda chamada para a função de conversão é evitada. A chamada para a função auxiliar `AfxA2Whelper` reduz o número de envios por push de argumento que deve ser feito para realizar a conversão (Isso resulta em código menor, que se chamado `MultiByteToWideChar` diretamente).

Em ordem para as macros ter espaço para armazenar a um comprimento temporário, é necessário declarar uma variável local chamada converter em que faz isso em cada função que usa as macros de conversão. Isso é feito invocando a macro definir USES_CONVERSION como visto acima no exemplo.

Há macros de conversão genérico e macros específicas do OLE. Esses dois conjuntos diferentes de macro são discutidos abaixo. Todas as macros residem em AFXPRIV. H.

## <a name="generic-conversion-macros"></a>Macros de conversão de genéricos

As macros de conversão genérico formam o mecanismo subjacente. O exemplo de macro e a implementação mostrada na seção anterior, A2W, é uma macro tal "genérica". Ele não está relacionado ao OLE especificamente. O conjunto de macros genéricos é listado abaixo:

```
A2CW      (LPCSTR) -> (LPCWSTR)
A2W      (LPCSTR) -> (LPWSTR)
W2CA      (LPCWSTR) -> (LPCSTR)
W2A      (LPCWSTR) -> (LPSTR)
```

Além de realizar conversões de texto, também há macros e funções auxiliares para converter `TEXTMETRIC`, `DEVMODE`, `BSTR`e OLE alocado cadeias de caracteres. Essas macros estão além do escopo desta discussão - consulte AFXPRIV. H para obter mais informações sobre essas macros.

## <a name="ole-conversion-macros"></a>Macros de conversão de OLE

As macros de conversão OLE são projetadas especificamente para manipular funções que esperam **OLESTR** caracteres. Se você examinar os cabeçalhos do OLE, você verá muitas referências a **LPCOLESTR** e **OLECHAR**. Esses tipos são usados para se referir ao tipo de caracteres usados em interfaces OLE de uma maneira que não é específico da plataforma. **OLECHAR** mapeia para **char** nas plataformas Win16 e Macintosh e **WCHAR** no Win32.

Para manter o número de **#ifdef** diretivas no MFC de código em um mínimo temos uma macro semelhante para cada conversão que onde as cadeias de caracteres OLE estão envolvidas. As macros a seguir são usadas com mais frequência:

```
T2COLE   (LPCTSTR) -> (LPCOLESTR)
T2OLE   (LPCTSTR) -> (LPOLESTR)
OLE2CT   (LPCOLESTR) -> (LPCTSTR)
OLE2T   (LPCOLESTR) -> (LPCSTR)
```

Novamente, há macros similares para fazer TEXTMETRIC, DEVMODE, BSTR e OLE alocado cadeias de caracteres. Consulte AFXPRIV. H para obter mais informações.

## <a name="other-considerations"></a>Outras considerações

Não use as macros em um loop estreito. Por exemplo, você não deseja escrever o seguinte tipo de código:

```
void BadIterateCode(LPCTSTR lpsz)
{
    USES_CONVERSION;
    for (int ii = 0; ii <10000; ii++)
    pI->SomeMethod(ii, T2COLE(lpsz));

}
```

O código acima pode resultar na alocação de megabytes de memória na pilha, dependendo de qual o conteúdo da cadeia de caracteres `lpsz` é! Ele também leva tempo para converter a cadeia de caracteres para cada iteração do loop. Em vez disso, mova essas conversões de constante para fora do loop:

```
void MuchBetterIterateCode(LPCTSTR lpsz)
{
    USES_CONVERSION;
    LPCOLESTR lpszT = T2COLE(lpsz);

    for (int ii = 0; ii <10000; ii++)
    pI->SomeMethod(ii, lpszT);

}
```

Se a cadeia de caracteres não for constante, em seguida, encapsule a chamada de método em uma função. Isso permitirá que o buffer de conversão a ser liberada a cada vez. Por exemplo:

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

Nunca retornam o resultado de uma das macros, a menos que o valor de retorno implica fazendo uma cópia dos dados antes de retornar. Por exemplo, esse código é ruim:

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

O código acima pode ser reparado, alterando o valor de retorno para algo que copia o valor:

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

As macros são fáceis de usar e fácil de inserir em seu código, mas como você pode ver nas condições acima, você precisa ter cuidado ao usá-los.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
