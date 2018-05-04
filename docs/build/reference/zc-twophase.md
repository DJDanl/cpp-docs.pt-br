---
title: /ZC:twoPhase-(desabilitar pesquisa de nome em duas fases) | Microsoft Docs
ms.custom: ''
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- twoPhase
- /Zc:twoPhase
- VC.Project.VCCLCompilerTool.EnforceTypeConversionRules
dev_langs:
- C++
helpviewer_keywords:
- twoPhase
- disable two-phase name lookup
- /Zc:twoPhase
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5653959b25105f10ae98768217524dc0ff0cbe2a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zctwophase--disable-two-phase-name-lookup"></a>/ZC:twoPhase-(pesquisa de nome em duas fases disable)

Quando o **/Zc:twoPhase-** opção for especificada, o compilador analisa e instancia os modelos de classe e de função da mesma maneira que as versões do Visual Studio antes do Visual Studio 2017 versão 15,3 não conforme. 

## <a name="syntax"></a>Sintaxe

> **/Zc:twoPhase-**

## <a name="remarks"></a>Comentários

No Visual Studio 2017 versão 15,3 e versões posteriores, por padrão, o compilador usa a pesquisa de nome em duas fases para resolução de nome de modelo. Se **/Zc:twoPhase-** for especificado, o compilador reverterá ao seu não conformes classe modelo e a função modelo nome resolução e substituição comportamento anterior.

O **/Zc:twoPhase-** opção para habilitar o comportamento não conformes não está definida por padrão. O [/ permissivo-](permissive-standards-conformance.md) opção implicitamente define o comportamento do compilador pesquisa em duas fases em conformidade, mas ele pode ser substituído usando **/Zc:twoPhase-**.

Os arquivos de cabeçalho do SDK do Windows na versão 10.0.15063.0 (criadores de atualização ou Redstone 2) e versões anteriores não funcionam corretamente no modo de conformidade. Você deve usar **/Zc:twoPhase-** para compilar o código para essas versões do SDK quando você usar a versão do Visual Studio de 2017 15,3 e versões posteriores. Versões do SDK do Windows, começando com a versão 10.0.15254.0 (3 Redstone ou queda criadores de atualização) funcionam corretamente no modo de conformidade e não requerem o **/Zc:twoPhase-** opção.

Use **/Zc:twoPhase-** se seu código requer o comportamento antigo para compilar corretamente. Considere seriamente atualizar seu código para estar de acordo com o padrão.

### <a name="compiler-behavior-under-zctwophase-"></a>Comportamento do compilador em /Zc:twoPhase-

Em versões do compilador antes do Visual Studio 2017 versão 15,3 e quando **/Zc:twoPhase-** for especificado, o compilador usa esse comportamento:

- Ele analisa somente a declaração de modelo, o cabeçalho de classe e a lista de classes base. Corpo do modelo é capturado como um fluxo do token. Nenhum corpo de função, inicializadores, argumentos padrão ou argumentos noexcept são analisados. O modelo de classe é instanciada pseudo em um tipo de tentativa para validar se as declarações no modelo de classe estão corretas. Considere este modelo de classe:

   ```cpp
   template <typename T> class Derived : public Base<T> { ... }
   ```

   A declaração de modelo, `template <typename T`>, o cabeçalho de classe `class Derived`e a lista de classe base `public Base<T>` são analisados, mas o corpo do modelo é capturado como um fluxo do token.

- Ao analisar um modelo de função, o compilador analisa somente a assinatura de função. O corpo da função nunca é analisado. Em vez disso, ele é capturado como um fluxo do token.

Como resultado, se o corpo de modelo tem erros de sintaxe e o modelo nunca é instanciado, os erros são nunca diagnosticados.

Outro efeito desse comportamento é na resolução de sobrecarga. Por causa da forma que o fluxo do token é expandido no site da instanciação, símbolos que não eram visíveis a declaração de modelo podem ser visíveis no ponto de instanciação e participar de resolução de sobrecarga. Isso pode levar a modelos que alteram o comportamento com base no código que não estava visível quando o modelo foi definido, ao contrário do padrão.

Por exemplo, pense neste código:

```cpp
#include <cstdio>

void func(void*) { std::puts("The call resolves to void*") ;}

template<typename T> void g(T x)
{
    func(0);
}

void func(int) { std::puts("The call resolves to int"); }

int main() 
{
    g(3.14);
}
```

Quando compilado no **/Zc:twoPhase-**, este programa imprime "chamada resolve para int". No modo de conformidade em **/ permissivo-**, este programa imprime "resolve a chamada para void *", porque a segunda sobrecarga de `func` não fica visível quando o compilador encontra o modelo.

*Nomes de dependente*, nomes que dependem de um parâmetro de modelo tem o comportamento de pesquisa que também é diferente em **/Zc:twoPhase-**. No modo de conformidade, os nomes de dependente não são vinculados no ponto da definição do modelo. Em vez disso, esses nomes são pesquisados quando o modelo é instanciado. Para chamadas de função com um nome de função dependente, o nome está associado ao conjunto de funções que são visíveis no ponto de chamada na definição do modelo, como acima. Sobrecargas adicionais de pesquisa dependente de argumento são adicionadas no ponto da definição do modelo e o ponto de onde o modelo é instanciado. As duas fases de pesquisa em duas fases são a pesquisa de nomes de dependente não no momento da definição de modelo e a pesquisa de nomes de dependente no momento da instanciação do modelo. Em **/Zc:twoPhase-**, o compilador não pesquisa dependente de argumento separadamente da pesquisa comum, não qualificada (ou seja, ele não faz pesquisa em duas fases), portanto, os resultados da resolução de sobrecarga podem ser diferentes.

Aqui está outro exemplo:

```cpp
// zctwophase1.cpp
// Compile by using
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

Quando compilado sem **/Zc:twoPhase-**, isso imprime

```Output
func(long)
NS::func(NS::S)
```

Quando compilado com **/Zc:twoPhase-**, isso imprime

```Output
func(int)
NS::func(NS::S)
```

No modo de conformidade em **/ permissivo-**, a chamada `tfunc(1729)` resolve para o `void func(long)` sobrecarga, não `void func(int)` sobrecarga no **/Zc:twoPhase-**, pois o não qualificado `func(int)` é declarado depois da definição do modelo e não localizados por meio de pesquisa dependente de argumento. Mas `void func(S)` participar pesquisa dependente de argumento, portanto, é adicionado para a sobrecarga definido para a chamada `tfunc(s)` mesmo que é declarado após a função do modelo.

### <a name="update-your-code-for-two-phase-conformance"></a>Atualize seu código para conformidade de duas fases

Versões mais antigas do compilador não exigem as palavras-chave `template` e `typename` everywhere C++ padrão requê-los. Essas palavras-chave é necessários em algumas posições para resolver a ambiguidade como compiladores devem analisar um nome dependente durante a primeira fase da pesquisa. Por exemplo:

`T::Foo<a || b>(c);`

Analisa um compilador de conformidade `Foo` como uma variável no escopo do `T`, que significa que esse código é uma lógica- ou uma expressão com `T::foo < a` como o operando esquerdo e `b > (c)` como operando à direita. Se deseja usar `Foo` como um modelo de função, você deve indicar que este é um modelo adicionando o `template` palavra-chave:

`T::template Foo<a || b>(c);`

Em versões anteriores do Visual Studio 2017 versão 15,3 e quando **/Zc:twoPhase-** for especificado, o compilador permite que esse código sem o `template` palavra-chave e o interpreta como uma chamada para um modelo de função com um argumento de `a || b`, pois ele analisa a modelos de maneira muito limitada. O código acima não é analisado em todos os na primeira etapa. Durante a segunda fase há contexto suficiente para informar que `T::Foo` é um modelo, em vez de uma variável para o compilador não impõe o uso da palavra-chave.

Esse comportamento também pode ser visto, eliminando a palavra-chave `typename` antes de nomes no corpo do modelo de função, inicializadores, argumentos padrão e noexcept argumentos. Por exemplo:

```cpp
template<typename T>
typename T::TYPE func(typename T::TYPE*)
{
    /* typename */ T::TYPE i;
}
```

Se você não usar a palavra-chave `typename` no corpo da função, esse código é compilado em **/Zc:twoPhase-**, mas não em **/ permissivo-**. O `typename` palavra-chave é necessário para indicar que o `TYPE` é dependente. O corpo não é analisada em **/Zc:twoPhase-**, o compilador does't requer a palavra-chave. Em **/ permissivo-** modo de conformidade, o código sem o `typename` palavra-chave gera erros. Para migrar seu código para Visual Studio 2017 versão 15,3 e fora dela, inserir o `typename` palavra-chave onde ele está ausente.

Da mesma forma, considere este exemplo de código:

```cpp
template<typename T>
typename T::template X<T>::TYPE func(typename T::TYPE)
{
    typename T::/* template */ X<T>::TYPE i;
}
```

Em **/Zc:twoPhase-** e compiladores mais antigos, o compilador só requer a `template` palavra-chave na linha 2. Por padrão e no modo de conformidade, o compilador agora também requer o `template` palavra-chave na linha 4 para indicar que `T::X<T>` é um modelo. Procure o código que está faltando a palavra-chave e fornecê-lo para tornar o código de acordo com o padrão.

Para obter mais informações sobre problemas de conformidade, consulte [melhorias de conformidade C++ no Visual Studio](../../cpp-conformance-improvements-2017.md) e [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/Zc:twoPhase-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
