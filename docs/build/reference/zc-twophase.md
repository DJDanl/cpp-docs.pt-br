---
title: /ZC:twoPhase-(desabilitar a pesquisa de nome em duas fases)
ms.date: 03/06/2018
f1_keywords:
- twoPhase
- /Zc:twoPhase
- VC.Project.VCCLCompilerTool.EnforceTypeConversionRules
helpviewer_keywords:
- twoPhase
- disable two-phase name lookup
- /Zc:twoPhase
ms.openlocfilehash: ebd577bc25a2789e3a6b328a4c9cd2e1596d04da
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57821388"
---
# <a name="zctwophase--disable-two-phase-name-lookup"></a>/ZC:twoPhase-(desabilitar a pesquisa de nome em duas fases)

Quando o **/Zc:twoPhase-** opção for especificada, o compilador analisa e cria uma instância de modelos de classe e modelos de função da mesma forma que as versões do Visual Studio anteriores ao Visual Studio 2017 versão 15.3 não conformes.

## <a name="syntax"></a>Sintaxe

> **/Zc:twoPhase-**

## <a name="remarks"></a>Comentários

No Visual Studio 2017 versão 15.3 e posterior, por padrão, o compilador usa a pesquisa de nome em duas fases para resolução de nome de modelo. Se **/Zc:twoPhase-** for especificado, o compilador será revertido para seu anterior não conformes modelo e a função modelo nome resolução e substituição de comportamento da classe.

O **/Zc:twoPhase-** opção para habilitar o comportamento não conformes não é definida por padrão. O [/permissive--](permissive-standards-conformance.md) opção define implicitamente o comportamento do compilador pesquisa em duas fases em conformidade, mas ele pode ser substituído usando **/Zc:twoPhase-**.

Os arquivos de cabeçalho do SDK do Windows na versão 10.0.15063.0 (atualização para criadores ou Redstone 2) e versões anteriores não funcionam corretamente no modo de conformidade. Você deve usar **/Zc:twoPhase-** para compilar o código para essas versões do SDK quando você usa o Visual Studio 2017 versão 15.3 e versões posteriores. Versões do SDK do Windows, começando com a versão 10.0.15254.0 (3 Redstone ou Fall Creators Update) funcionam corretamente no modo de conformidade e não exigem o **/Zc:twoPhase-** opção.

Use **/Zc:twoPhase-** se seu código exigir o comportamento antigo para compilar corretamente. Considere seriamente atualizar seu código para estar em conformidade com o padrão.

### <a name="compiler-behavior-under-zctwophase-"></a>Comportamento do compilador em /Zc:twoPhase-

Nas versões do compilador antes do Visual Studio 2017 versão 15.3 e quando **/Zc:twoPhase-** for especificado, o compilador usa esse comportamento:

- Ele analisa somente a declaração de modelo, o cabeçalho de classe e a lista de classes base. Corpo do modelo é capturado como um fluxo do token. Não há corpos de função, inicializadores, os argumentos padrão ou noexcept argumentos são analisados. O modelo de classe é instanciada pseudo em um tipo provisório para validar que as declarações no modelo de classe estão corretas. Considere este modelo de classe:

   ```cpp
   template <typename T> class Derived : public Base<T> { ... }
   ```

   A declaração de modelo `template <typename T`>, título da classe `class Derived`e a lista de classe base `public Base<T>` são analisados, mas o corpo do modelo é capturado como um fluxo do token.

- Ao analisar um modelo de função, o compilador analisa somente a assinatura de função. O corpo da função nunca é analisado. Em vez disso, ela é capturada como um fluxo do token.

Como resultado, se o corpo do modelo tem erros de sintaxe e o modelo nunca é instanciado, os erros nunca são diagnosticados.

Outro efeito desse comportamento é na resolução de sobrecarga. Por causa da maneira que o fluxo do token é expandido no site da instanciação, símbolos que não eram visíveis a declaração de modelo podem ser visíveis no ponto de instanciação e participa da resolução de sobrecarga. Isso pode levar a modelos que alteram o comportamento com base no código que não estava visível quando o modelo tiver sido definido, ao contrário do padrão.

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

Quando compilado com **/Zc:twoPhase-**, esse programa imprime "a chamada resolve para int". No modo de conformidade sob **/permissive--**, esse programa imprime "resolve a chamada para void *", porque a segunda sobrecarga do `func` não fica visível quando o compilador encontra o modelo.

*Nomes de dependente*, os nomes que dependem de um parâmetro de modelo, têm o comportamento de pesquisa que também é diferente em **/Zc:twoPhase-**. No modo de conformidade, os nomes dependentes não estão associados no ponto de definição do modelo. Em vez disso, esses nomes são pesquisados quando o modelo é instanciado. Para chamadas de função com um nome de função dependente, o nome é associado ao conjunto de funções que são visíveis no ponto de chamada na definição do modelo, como mostrado acima. Sobrecargas adicionais de pesquisa dependente de argumento são adicionadas no ponto da definição do modelo e o ponto de onde o modelo é instanciado. As duas fases de pesquisa em duas fases são a pesquisa para nomes não dependentes no momento da definição de modelo e pesquisa para nomes dependentes no momento da instanciação do modelo. Sob **/Zc:twoPhase-**, o compilador não faz pesquisa dependente de argumento separadamente de pesquisa comum, não qualificada (ou seja, ele não faz pesquisa em duas fases), portanto, os resultados da resolução de sobrecarga podem ser diferentes.

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

No modo de conformidade sob **/permissive--**, a chamada `tfunc(1729)` resolve para o `void func(long)` sobrecarga, não `void func(int)` sobrecarregar como nas **/Zc:twoPhase-**, pois não qualificada `func(int)` é declarada após a definição do modelo e não foi encontrado por meio de pesquisa dependente de argumento. Mas `void func(S)` participa na pesquisa dependente de argumento, para que ele seja adicionado para a sobrecarga definido para a chamada `tfunc(s)` , mesmo que ela é declarada após a função de modelo.

### <a name="update-your-code-for-two-phase-conformance"></a>Atualizar seu código para conformidade de duas fases

Versões mais antigas do compilador não exigem as palavras-chave `template` e `typename` em todos os lugares, o padrão C++ requê-los. Essas palavras-chave é necessárias algumas posições para resolver a ambiguidade como compiladores devem analisar um nome dependente durante a primeira fase da pesquisa. Por exemplo:

`T::Foo<a || b>(c);`

Analisa um compilador em conformidade `Foo` como uma variável no escopo de `T`, que significa que esse código é uma lógica- ou expressão com `T::foo < a` como o operando esquerdo e `b > (c)` como o operando à direita. Se você pretende usar `Foo` como um modelo de função, você deve indicar que este é um modelo adicionando o `template` palavra-chave:

`T::template Foo<a || b>(c);`

Em versões anteriores do Visual Studio 2017 versão 15.3 e quando **/Zc:twoPhase-** for especificado, o compilador permite que esse código sem o `template` palavra-chave e o interpreta como uma chamada para um modelo de função com um argumento `a || b`, pois ele analisa os modelos de maneira muito limitado. O código acima não é analisado em todos os na primeira fase. Durante a segunda fase não há contexto suficiente para dizer que `T::Foo` é um modelo em vez de uma variável para que o compilador não imponha o uso da palavra-chave.

Esse comportamento também pode ser visto, eliminando a palavra-chave `typename` antes de nomes em corpos de modelo de função, inicializadores, os argumentos padrão e argumentos de noexcept. Por exemplo:

```cpp
template<typename T>
typename T::TYPE func(typename T::TYPE*)
{
    /* typename */ T::TYPE i;
}
```

Se você não usar a palavra-chave `typename` no corpo da função, esse código é compilado em **/Zc:twoPhase-**, mas não está **/permissive--**. O `typename` palavra-chave é necessário para indicar que o `TYPE` é dependente. Porque o corpo não é analisado em **/Zc:twoPhase-**, o compilador does't exigem a palavra-chave. Na **/permissive--** modo de conformidade, o código sem o `typename` palavra-chave gera erros. Para migrar seu código para Visual Studio 2017 versão 15.3 e posteriores, inserir o `typename` palavra-chave onde ele está ausente.

Da mesma forma, considere este exemplo de código:

```cpp
template<typename T>
typename T::template X<T>::TYPE func(typename T::TYPE)
{
    typename T::/* template */ X<T>::TYPE i;
}
```

Sob **/Zc:twoPhase-** e nos compiladores antigos, o compilador só requer a `template` palavra-chave na linha 2. Por padrão e no modo de conformidade, o compilador agora também requer o `template` palavra-chave na linha 4 para indicar que `T::X<T>` é um modelo. Procure o código que está faltando a palavra-chave this e fornecê-lo para tornar seu código de acordo com o padrão.

Para obter mais informações sobre problemas de conformidade, consulte [aprimoramentos de conformidade do C++ no Visual Studio](../../cpp-conformance-improvements-2017.md) e [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/Zc:twoPhase-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
