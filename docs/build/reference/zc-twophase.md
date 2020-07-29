---
title: /Zc:twoPhase- (desabilitar a pesquisa de nome de duas fases)
description: 'Explica como/Zc: twoPhase-desabilita a pesquisa de nome de duas fases quando/permissive-é especificado.'
ms.date: 12/03/2019
f1_keywords:
- twoPhase
- /Zc:twoPhase
helpviewer_keywords:
- twoPhase
- disable two-phase name lookup
- /Zc:twoPhase
ms.openlocfilehash: 712503d08221d29a61323946008f2f36a467cb31
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234322"
---
# <a name="zctwophase--disable-two-phase-name-lookup"></a>/Zc:twoPhase- (desabilitar a pesquisa de nome de duas fases)

A **/Zc: twoPhase-** Option, em **/permissive-**, informa ao compilador para usar o comportamento de compilador original e não compatível do Microsoft C++ para analisar e instanciar modelos de classe e modelos de função.

## <a name="syntax"></a>Sintaxe

> **/Zc: twoPhase-**

## <a name="remarks"></a>Comentários

Visual Studio 2017 versão 15,3 e posterior: em [/permissive-](permissive-standards-conformance.md), o compilador usa a pesquisa de nome de duas fases para resolução de nome de modelo. Se você também especificar **/Zc: twoPhase-**, o compilador reverterá para seu modelo de classe não compatível anterior e o comportamento de substituição e a resolução de nome do modelo de função. Quando **/permissive-** não é especificado, o comportamento não compatível é o padrão.

Os arquivos de cabeçalho SDK do Windows na versão 10.0.15063.0 (Creators Update ou RS2) e anteriores não funcionam no modo de conformidade. **/Zc: twoPhase-** é necessário para compilar o código para essas versões do SDK quando você usa o **/permissive-**. As versões do SDK do Windows a partir da versão 10.0.15254.0 (atualização para criadores do outono ou RS3) funcionam corretamente no modo de conformidade. Eles não exigem a opção **/Zc: twoPhase** .

Use **/Zc: twoPhase-** se seu código exigir que o comportamento antigo seja compilado corretamente. É altamente recomendável atualizar seu código para estar de acordo com o padrão.

### <a name="compiler-behavior-under-zctwophase-"></a>Comportamento do compilador em/Zc: twoPhase-

Por padrão, ou no Visual Studio 2017 versão 15,3 e posteriores quando você especifica **/permissive-** e **/Zc: twoPhase-**, o compilador usa esse comportamento:

- Ele analisa apenas a declaração de modelo, o cabeçalho de classe e a lista de classes base. O corpo do modelo é capturado como um fluxo de token. Nenhum corpo de função, inicializadores, argumentos padrão ou argumentos noexcept são analisados. O modelo de classe é pseudo instanciado em um tipo provisório para validar que as declarações no modelo de classe estão corretas. Considere este modelo de classe:

   ```cpp
   template <typename T> class Derived : public Base<T> { ... }
   ```

   A declaração de modelo, `template <typename T>` , o cabeçalho de classe `class Derived` e a lista de classe base `public Base<T>` são analisados, mas o corpo do modelo é capturado como um fluxo de token.

- Ao analisar um modelo de função, o compilador analisa apenas a assinatura de função. O corpo da função nunca é analisado. Em vez disso, ele é capturado como um fluxo de token.

Como resultado, se o corpo do modelo tiver erros de sintaxe, mas o modelo nunca for instanciado, o compilador não diagnosticará os erros.

Outro efeito desse comportamento é na resolução de sobrecarga. O comportamento não padrão ocorre devido à maneira como o fluxo de token é expandido no site de instanciação. Os símbolos que não estavam visíveis na declaração de modelo podem estar visíveis no ponto de instanciação. Isso significa que eles podem participar da resolução de sobrecarga. Você pode achar que os modelos alteram o comportamento com base no código que não estava visível na definição do modelo, ao contrário do padrão.

Por exemplo, considere este código:

```cpp
// zctwophase.cpp
// To test options, compile by using
// cl /EHsc /nologo /W4 zctwophase.cpp
// cl /EHsc /nologo /W4 /permissive- zctwophase.cpp
// cl /EHsc /nologo /W4 /permissive- /Zc:twoPhase- zctwophase.cpp

#include <cstdio>

void func(long) { std::puts("Standard two-phase") ;}

template<typename T> void g(T x)
{
    func(0);
}

void func(int) { std::puts("Microsoft one-phase"); }

int main()
{
    g(6174);
}
```

Aqui está a saída quando você usa o modo padrão, o modo de conformidade e o modo de conformidade com **/Zc: twoPhase-** opções do compilador:

```cmd
C:\Temp>cl /EHsc /nologo /W4 zctwophase.cpp && zctwophase
zctwophase.cpp
Microsoft one-phase

C:\Temp>cl /EHsc /nologo /W4 /permissive- zctwophase.cpp && zctwophase
zctwophase.cpp
Standard two-phase

C:\Temp>cl /EHsc /nologo /W4 /permissive- /Zc:twoPhase- zctwophase.cpp && zctwophase
zctwophase.cpp
Microsoft one-phase
```

Quando compilado no modo de conformidade em **/permissive-**, este programa imprime " `Standard two-phase` ", porque a segunda sobrecarga de `func` não é visível quando o compilador atinge o modelo. Se você adicionar **/Zc: twoPhase –**, o programa imprime " `Microsoft one-phase` ". A saída é a mesma de quando você não especifica **/permissive-**.

*Nomes dependentes* são nomes que dependem de um parâmetro de modelo. Esses nomes têm comportamento de pesquisa que também é diferente em **/Zc: twoPhase-**. No modo de conformidade, os nomes dependentes não são associados no ponto da definição do modelo. Em vez disso, o compilador os procura ao criar uma instância do modelo. Para chamadas de função com um nome de função dependente, o nome é associado a funções visíveis no site de chamada na definição do modelo. As sobrecargas adicionais da pesquisa dependente de argumento são adicionadas, ambas no ponto da definição do modelo e no ponto da instanciação do modelo.

A pesquisa de duas fases consiste em duas partes: a pesquisa de nomes não dependentes durante a definição do modelo e a pesquisa de nomes dependentes durante a instanciação do modelo. Em **/Zc: twoPhase-**, o compilador não faz pesquisa dependente de argumento separadamente de uma pesquisa não qualificada. Ou seja, ele não faz a pesquisa de duas fases, portanto, os resultados da resolução de sobrecarga podem ser diferentes.

Veja outro exemplo:

```cpp
// zctwophase1.cpp
// To test options, compile by using
// cl /EHsc /W4 zctwophase1.cpp
// cl /EHsc /W4 /permissive- zctwophase1.cpp
// cl /EHsc /W4 /permissive- /Zc:twoPhase- zctwophase1.cpp

#include <cstdio>

void func(long) { std::puts("func(long)"); }

template <typename T> void tfunc(T t) {
    func(t);
}

void func(int) { std::puts("func(int)"); }

namespace NS {
    struct S {};
    void func(S) { std::puts("NS::func(NS::S)"); }
}

int main() {
    tfunc(1729);
    NS::S s;
    tfunc(s);
}
```

Quando compilado sem **/permissive-**, esse código imprime:

```Output
func(int)
NS::func(NS::S)
```

Quando compilado com **/permissive-**, mas sem **/Zc: twoPhase-**, esse código imprime:

```Output
func(long)
NS::func(NS::S)
```

Quando compilado com **/permissive-** e **/Zc: twoPhase-**, esse código imprime:

```Output
func(int)
NS::func(NS::S)
```

No modo de conformidade em **/permissive-**, a chamada `tfunc(1729)` resolve para a `void func(long)` sobrecarga. Ele não é resolvido para a `void func(int)` sobrecarga, como em **/Zc: twoPhase-**. Isso ocorre porque o não qualificado `func(int)` é declarado após a definição do modelo e não é encontrado por meio de pesquisa dependente de argumento. Mas `void func(S)` participa da pesquisa dependente de argumento e, portanto, é adicionada ao conjunto de sobrecarga para a chamada `tfunc(s)` , mesmo que seja declarada após a função de modelo.

### <a name="update-your-code-for-two-phase-conformance"></a>Atualizar seu código para conformidade em duas fases

As versões mais antigas do compilador não exigem as palavras-chave **`template`** e **`typename`** todos os lugares em que o C++ Standard exige. Essas palavras-chave são necessárias em algumas posições para desambiguar como os compiladores devem analisar um nome dependente durante a primeira fase de pesquisa. Por exemplo:

`T::Foo<a || b>(c);`

Um compilador em conformidade é analisado `Foo` como uma variável no escopo de `T` , o que significa que esse código é uma expressão or lógica com `T::foo < a` como o operando esquerdo e `b > (c)` como o operando à direita. Se você quer usar `Foo` como um modelo de função, você deve indicar que é um modelo adicionando a **`template`** palavra-chave:

`T::template Foo<a || b>(c);`

Em versões do Visual Studio 2017 versão 15,3 e posteriores, quando **/permissive-** e **/Zc: twoPhase-** são especificados, o compilador permite esse código sem a **`template`** palavra-chave. Ele interpreta o código como uma chamada para um modelo de função com um argumento de `a || b` , porque ele só analisa modelos de maneira limitada. O código acima não é analisado na primeira fase. Durante a segunda fase, há contexto suficiente para dizer que `T::Foo` é um modelo em vez de uma variável, portanto, o compilador não impõe o uso da palavra-chave.

Esse comportamento também pode ser visto eliminando a palavra-chave **`typename`** antes dos nomes nos corpos do modelo de função, inicializadores, argumentos padrão e argumentos noexcept. Por exemplo:

```cpp
template<typename T>
typename T::TYPE func(typename T::TYPE*)
{
    /* typename */ T::TYPE i;
}
```

Se você não usar a palavra-chave **`typename`** no corpo da função, esse código será compilado em **/permissive-/Zc: twoPhase-**, mas não em **/permissive-** sozinho. A **`typename`** palavra-chave é necessária para indicar que o `TYPE` é dependente. Como o corpo não é analisado em **/Zc: twoPhase-**, o compilador does't requer a palavra-chave. No modo de conformidade do **/permissive-** , o código sem a **`typename`** palavra-chave gera erros. Para migrar seu código para conformidade no Visual Studio 2017 versão 15,3 e posterior, insira a **`typename`** palavra-chave onde ela está ausente.

Da mesma forma, considere este exemplo de código:

```cpp
template<typename T>
typename T::template X<T>::TYPE func(typename T::TYPE)
{
    typename T::/* template */ X<T>::TYPE i;
}
```

Em **/permissive-/Zc: twoPhase-** e em compiladores mais antigos, o compilador requer apenas a **`template`** palavra-chave na linha 2. No modo de conformidade, o compilador agora também requer a **`template`** palavra-chave na linha 4 para indicar que `T::X<T>` é um modelo. Procure o código que não tem essa palavra-chave e forneça-o para que seu código esteja em conformidade com o padrão.

Para obter mais informações sobre problemas de conformidade, consulte [melhorias de conformidade do C++ no Visual Studio](../../overview/cpp-conformance-improvements.md) e [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc: twoPhase-** e escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)
